#include <iostream>

using namespace std;

// Legacy class (incompatible interface)
class OldPrinter {
public:
    void oldPrint() {
        cout << "Printing using OldPrinter\n";
    }
};

// Target interface
class NewPrinter {
public:
    virtual void print() = 0;
};

// Adapter class
class PrinterAdapter : public NewPrinter {
private:
    OldPrinter* oldPrinter;
public:
    PrinterAdapter(OldPrinter* printer) : oldPrinter(printer) {}

    void print() override {
        oldPrinter->oldPrint(); // Adapt old method to new interface
    }
};


// Complex subsystem classes
class CPU {
public:
    void start() { cout << "CPU started\n"; }
};

class Memory {
public:
    void load() { cout << "Memory loaded\n"; }
};

class HardDrive {
public:
    void read() { cout << "Reading from Hard Drive\n"; }
};

// Facade class
class Computer {
private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
public:
    void startComputer() {
        cpu.start();
        memory.load();
        hardDrive.read();
    }
};



int main() {
    // Adapter Pattern
    OldPrinter* oldPrinter = new OldPrinter();
    NewPrinter* printer = new PrinterAdapter(oldPrinter);
    printer->print();  // Output: Printing using OldPrinter
    delete oldPrinter;
    delete printer;

    // Facade Pattern
    Computer computer;
    computer.startComputer();
    // Output:
    // CPU started
    // Memory loaded
    // Reading from Hard Drive
    return 0;
}
