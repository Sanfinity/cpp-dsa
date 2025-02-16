#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Node {
public:
    Node<T>* next;
    T data;
    Node(T value) : next(nullptr), data(value) {}
};

class StaticStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    StaticStack(int size) {
        capacity = size;
        top = -1;
        arr = new int[size];
    }

    ~StaticStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top >= capacity - 1;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = data;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }
};

template <typename T>
class DynamicStack {
private:
    Node<T>* top;
    int size;

public:
    DynamicStack() {
        top = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!top) {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!";
            return -1;
        }
        auto deleteNode = top;
        auto value = top->data;
        top = top->next;
        delete deleteNode;
        size--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack Underflow!";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }
};

int main()
{
    cout << "\n###### Start of Program ######\n" << endl;
    cout << "\nStatic Stack" << endl;
    StaticStack s1(5);

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << "Top element: " << s1.peek() << endl;

    cout << "Popped element: " << s1.pop() << endl;
    cout << "Popped element: " << s1.pop() << endl;
    cout << "Popped element: " << s1.pop() << endl;
    cout << "Popped element: " << s1.pop() << endl;


    cout << "\nDynamic Stack" << endl;
    DynamicStack<int> s2;

    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s2.push(50);

    cout << "Top element: " << s2.peek() << endl;

    cout << "Current size: " << s2.getSize() << endl;
    cout << "Popped element: " << s2.pop() << endl;
    cout << "Popped element: " << s2.pop() << endl;
    cout << "Popped element: " << s2.pop() << endl;
    cout << "Popped element: " << s2.pop() << endl;
    cout << "Current size: " << s2.getSize() << endl;

    cout << "\nSTL Stack" << endl;
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Current size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Popped element: " << s.top() << endl;
    s.pop();
    cout << "Popped element: " << s.top() << endl;
    s.pop();
    cout << "Popped element: " << s.top() << endl;
    s.pop();
    cout << "Popped element: " << s.top() << endl;
    s.pop();
    cout << "Current size: " << s.size() << endl;

    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }

    cout << "\n### Explorations ###" << endl;
    stack<int> foo, bar;
    foo.push(10); foo.push(20); foo.push(30);
    bar.push(111); bar.push(222);

    foo.swap(bar);

    cout << "size of foo: " << foo.size() << '\n';
    cout << "size of bar: " << bar.size() << '\n';


    cout << "\n######  End of Program  ######\n" << endl;
    return 0;
}