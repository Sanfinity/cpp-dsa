#include <iostream>
#include <vector>

using namespace std;

// ========== 1. OBSERVER PATTERN ==========
// Notifies multiple objects about state changes

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& news) = 0;
};

class NewsAgency {
private:
    vector<Observer*> Observers;
    string news;

    void notifyObservers() {
        std::cout << "Broadcasting news to " << Observers.size() << " subscribers..." << std::endl;
        for (Observer* observer : Observers) {
            observer->update(news);
        }
    }

public:
    void addObserver(Observer* observer) {
        Observers.emplace_back(observer);
    }

    void removeObserver(Observer* observer) {
        Observers.erase(remove(Observers.begin(), Observers.end(), observer), Observers.end());
    }

    void setNews(const std::string& newNews) {
        news = newNews;
        notifyObservers();
    }
};

class NewsChannel : public Observer {
private:
    std::string channelName;

public:
    NewsChannel(const std::string& name) : channelName(name) {};
    void update(const std::string& news) override {
        std::cout << channelName << " received: " << news << std::endl;
    }
};

// ========== 2. ITERATOR PATTERN ==========
// Provides a way to access elements sequentially without exposing structure

template<typename T>
class SimpleList {
private:
    std::vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    // Iterator class
    class Iterator {
    private:
        typename std::vector<T>::iterator current;
        typename std::vector<T>::iterator end;

    public:
        Iterator(typename std::vector<T>::iterator start, typename std::vector<T>::iterator finish)
            : current(start), end(finish) {
        }

        bool hasNext() const {
            return current != end;
        }

        T& next() {
            return *current++;
        }
    };

    Iterator createIterator() {
        return Iterator(items.begin(), items.end());
    }
};

// ========== 3. STRATEGY PATTERN ==========
// Defines family of algorithms and makes them interchangeable

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(double amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;

public:
    CreditCardPayment(const std::string& cardNumber) : cardNumber(cardNumber) {};

    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using Credit Card ending in "
            << cardNumber.substr(cardNumber.length() - 4) << std::endl;
    }
};

class UPIPayment : public PaymentStrategy {
private:
    std::string upiID;

public:
    UPIPayment(const std::string& upiID) : upiID(upiID) {};

    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using UPI ID "
            << upiID << std::endl;
    }
};

class ShoppingCart {
private:
    std::unique_ptr<PaymentStrategy> paymentMethod;
    double totalAmount{ 0 };

public:
    void addItem(double price) {
        totalAmount += price;
        std::cout << "Added item worth $" << price << " (Total: $" << totalAmount << ")" << std::endl;
    }

    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> strategy) {
        paymentMethod = std::move(strategy);
    }

    void checkout() {
        if (paymentMethod && totalAmount > 0) {
            paymentMethod->pay(totalAmount);
            totalAmount = 0;
        }
    }
};

// ========== 4. MEDIATOR PATTERN ==========
// Defines how objects interact with each other through a mediator

class User; // Forward declaration

class ChatMediator {
public:
    virtual ~ChatMediator() = default;
    virtual void sendMessage(const std::string& message, User* sender) = 0;
};

class User {
protected:
    ChatMediator* mediator;
    std::string name;

public:
    User(ChatMediator* med, const std::string& userName) : mediator(med), name(userName) {}
    virtual ~User() = default;

    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message, const std::string& from) = 0;

    std::string getName() const { return name; }
};

class ConcreteUser : public User {
public:
    ConcreteUser(ChatMediator* med, const std::string& userName) : User(med, userName) {}

    void send(const std::string& message) override {
        std::cout << name << " sends: " << message << std::endl;
        mediator->sendMessage(message, this);
    }

    void receive(const std::string& message, const std::string& from) override {
        std::cout << name << " received from " << from << ": " << message << std::endl;
    }
};

class ChatRoom : public ChatMediator {
private:
    std::vector<User*> users;

public:
    void addUser(User* user) {
        users.push_back(user);
        std::cout << user->getName() << " joined the chat room" << std::endl;
    }

    void sendMessage(const std::string& message, User* sender) override {
        for (User* user : users) {
            if (user != sender) {
                user->receive(message, sender->getName());
            }
        }
    }
};

// ========== 5. STATE PATTERN ==========
// Allows object to change behavior when internal state changes

class TrafficLight;

class TrafficLightState {
public:
    virtual ~TrafficLightState() = default;
    virtual void handle(TrafficLight* light) = 0;
    virtual std::string getColor() const = 0;
};

class TrafficLight {
private:
    std::unique_ptr<TrafficLightState> currentState;

public:
    TrafficLight();

    void setState(std::unique_ptr<TrafficLightState> newState) {
        currentState = std::move(newState);
    }

    void change() {
        std::cout << "Current: " << currentState->getColor() << " light" << std::endl;
        currentState->handle(this);
    }

    std::string getCurrentColor() const {
        return currentState ? currentState->getColor() : "Unknown";
    }
};

class RedState :public TrafficLightState {
public:
    void handle(TrafficLight* light) override;
    std::string getColor() const override {
        return "Red";
    }
};
class YellowState :public TrafficLightState {
    void handle(TrafficLight* light) override;
    std::string getColor() const override {
        return "Yellow";
    }
};
class GreenState :public TrafficLightState {
    void handle(TrafficLight* light) override;
    std::string getColor() const override {
        return "Green";
    }
};

void RedState::handle(TrafficLight* light) {
    std::cout << "Red -> Green (Go!)" << std::endl;
    return light->setState(make_unique<GreenState>());
}
void YellowState::handle(TrafficLight* light) {
    std::cout << "Yellow -> Red (Stop!)" << std::endl;
    return light->setState(make_unique<RedState>());
}
void GreenState::handle(TrafficLight* light) {
    std::cout << "Green -> Yellow (Caution!)" << std::endl;
    return light->setState(make_unique<YellowState>());
}

TrafficLight::TrafficLight() {
    currentState = std::make_unique<RedState>();
}

int main()
{
    std::cout << "=== OBSERVER PATTERN ===" << std::endl;
    std::cout << "Multiple news channels get notified when news agency publishes news\n" << std::endl;

    NewsAgency agency;
    NewsChannel cnn("CNN");
    NewsChannel bbc("BBC");
    NewsChannel fox("Fox News");

    agency.addObserver(&cnn);
    agency.addObserver(&bbc);
    agency.addObserver(&fox);

    agency.setNews("Breaking: New C++ standard released!");
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////

    std::cout << "=== ITERATOR PATTERN ===" << std::endl;
    std::cout << "Iterate through a collection without knowing its internal structure\n" << std::endl;

    SimpleList<std::string> playlist;
    playlist.add("Song 1: Bohemian Rhapsody");
    playlist.add("Song 2: Stairway to Heaven");
    playlist.add("Song 3: Hotel California");

    std::cout << "Playing playlist:" << std::endl;
    auto iterator = playlist.createIterator();
    while (iterator.hasNext()) {
        std::cout << "" << iterator.next() << std::endl;
    }
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////

    std::cout << "=== STRATEGY PATTERN ===" << std::endl;
    std::cout << "Different payment methods can be used interchangeably\n" << std::endl;

    ShoppingCart cart;
    cart.addItem(25.99);
    cart.addItem(15.50);

    // Try different payment strategies
    std::cout << "\n1st checkout - Credit Card:" << std::endl;
    cart.setPaymentStrategy(std::make_unique<CreditCardPayment>("1234-5678-9012-3456"));
    cart.checkout();
    std::cout << std::endl;

    cart.addItem(45.00);
    std::cout << "\n2nd checkout - PayPal:" << std::endl;
    cart.setPaymentStrategy(std::make_unique<UPIPayment>("123456789@oksbi"));
    cart.checkout();
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////

    std::cout << "=== MEDIATOR PATTERN ===" << std::endl;
    std::cout << "Users communicate through a chat room mediator\n" << std::endl;

    ChatRoom chatRoom;

    ConcreteUser alice(&chatRoom, "Alice");
    ConcreteUser bob(&chatRoom, "Bob");
    ConcreteUser charlie(&chatRoom, "Charlie");

    chatRoom.addUser(&alice);
    chatRoom.addUser(&bob);
    chatRoom.addUser(&charlie);

    std::cout << std::endl;
    alice.send("Hello everyone!");
    bob.send("Hey Alice! How are you?");
    charlie.send("Good morning folks!");
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////

    std::cout << "=== STATE PATTERN ===" << std::endl;
    std::cout << "Traffic light changes behavior based on its current state\n" << std::endl;

    TrafficLight light;

    std::cout << "Traffic light cycle:" << std::endl;
    for (int i = 0; i < 6; i++) {
        light.change();
        std::cout << "-> Now showing: " << light.getCurrentColor() << " light\n" << std::endl;
    }

    ///////////////////////////////////////////////////////////////////////////////////////

}
