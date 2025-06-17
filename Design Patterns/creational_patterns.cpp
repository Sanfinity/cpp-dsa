#include <iostream>
#include <string>

using namespace std;

// ========== 1. FACTORY PATTERN ==========
// Creates objects without specifying exact classes

class Animal {
public:
    virtual void makesound() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makesound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makesound() override {
        cout << "Meow!" << endl;
    }
};

class AnimalFactory {
public:
    static std::unique_ptr<Animal> createAnimal(const std::string& input) {
        if (input == "dog") {
            return make_unique<Dog>();
        }
        if (input == "cat") {
            return make_unique<Cat>();
        }
        return make_unique<Dog>();
    }
};

// ========== 2. BUILDER PATTERN ==========
// Constructs complex objects step by step

class Pizza {
private:
    std::string size;
    bool cheese{ false };
    bool mushroom{ false };
    bool pepperoni{ false };

public:
    class PizzaBuilder {
    private:
        std::string size;
        bool cheese{ false };
        bool mushroom{ false };
        bool pepperoni{ false };

    public:
        PizzaBuilder(const std::string& pizzaSize) :size(pizzaSize) {}
        PizzaBuilder& addCheese() {
            cheese = true;
            return *this;
        }
        PizzaBuilder& addMushroom() {
            mushroom = true;
            return *this;
        }
        PizzaBuilder& addPepperoni() {
            pepperoni = true;
            return *this;
        }

        Pizza build() {
            Pizza pizza;
            pizza.size = this->size;
            pizza.cheese = this->cheese;
            pizza.mushroom = this->mushroom;
            pizza.pepperoni = this->pepperoni;
            return pizza;
        }
    };
    void display() {
        std::cout << "Pizza: " << size << " - Cheese: " << cheese
            << ", Pepperoni: " << pepperoni
            << ", Mushrooms: " << mushroom << std::endl;
    }
};

// ========== 3. SINGLETON PATTERN ==========
// Ensures only one instance of a class exists

class DatabaseConnection {
private:
    std::string ConnectionString;
    static DatabaseConnection* instance;

    DatabaseConnection() : ConnectionString("Connected") {
        cout << "Connecting to database with status: " << ConnectionString << endl;
    }

public:
    // Disable copy and assignment operator
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    static DatabaseConnection* getInstance() {
        if (instance == nullptr) {
            instance = new DatabaseConnection;
        }
        return instance;
    }

    void query(const std::string& sql) {
        std::cout << "Executing: " << sql << std::endl;
    }

    void cleanup() {
        delete instance;
        instance = nullptr;
    }
};
// Initialize static member
DatabaseConnection* DatabaseConnection::instance = nullptr;

// ========== 4. PROTOTYPE PATTERN ==========
// Creates objects by cloning existing instances

class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& inputColor) : color(inputColor) {};
    virtual ~Shape() = default;
    virtual unique_ptr<Shape> clone() = 0;
    virtual void display() = 0;
};

class Rectangle : public Shape {
private:
    int length, width;

public:
    Rectangle(const std::string& color, int length, int width) : Shape(color), length(length), width(width) {};

    unique_ptr<Shape> clone() override {
        return make_unique<Rectangle>(*this);
    }

    void display() override {
        std::cout << "Rectangle - Color: " << color
            << ", Width: " << width
            << ", Length: " << length << std::endl;
    }
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(const std::string& color, int radius)
        : Shape(color), radius(radius) {
    }

    std::unique_ptr<Shape> clone() override {
        return std::make_unique<Circle>(*this);
    }

    void display() override {
        std::cout << "Circle - Color: " << color
            << ", Radius: " << radius << std::endl;
    }
};

int main()
{
    std::cout << "=== FACTORY PATTERN ===" << std::endl;
    auto dog = AnimalFactory::createAnimal("dog");
    auto cat = AnimalFactory::createAnimal("cat");
    dog->makesound();
    cat->makesound();

    std::cout << "\n=== BUILDER PATTERN ===" << std::endl;
    Pizza pizza = Pizza::PizzaBuilder("Normal").addCheese().addMushroom().addPepperoni().build();
    pizza.display();

    std::cout << "\n=== SINGLETON PATTERN ===" << std::endl;
    DatabaseConnection* db1 = DatabaseConnection::getInstance();
    DatabaseConnection* db2 = DatabaseConnection::getInstance();
    std::cout << "Same instance? " << (db1 == db2) << std::endl;
    db1->query("SELECT * FROM users");

    std::cout << "\n=== PROTOTYPE PATTERN ===" << std::endl;
    Circle originalCircle("Red", 5);
    Rectangle originalRect("Blue", 10, 20);

    auto clonedCircle = originalCircle.clone();
    auto clonedRect = originalRect.clone();

    std::cout << "Original: ";
    originalCircle.display();
    std::cout << "Cloned: ";
    clonedCircle->display();
}
