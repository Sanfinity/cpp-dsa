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

}
