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

class DynamicStackUsingArray {
private:
    int* arr;
    int capacity;
    int top;

public:
    DynamicStackUsingArray(int size = 2) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~DynamicStackUsingArray() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity;
    }

    void resize(int newCapacity) {
        int* newArray = new int[newCapacity];
        for (int i = 0; i <= top;i++) {
            newArray[i] = arr[i];
        }
        delete[] arr;
        arr = newArray;
        capacity = newCapacity;
    }

    void push(int data) {
        if (isFull()) {
            resize(capacity * 2);
        }
        arr[++top] = data;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        auto popElement = arr[top--];
        // Reduce the size of the array when the stack is 1/4 filled
        if (top + 1 <= capacity / 4 && capacity > 2) {
            resize(capacity / 2);
        }
        return popElement;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
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


    cout << "\nDynamic Stack using linked list" << endl;
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

    cout << "\nDynamic Stack using Array" << endl;
    DynamicStackUsingArray s3;

    s3.push(10);
    s3.push(20);
    s3.push(30);
    s3.push(40);
    s3.push(50);

    cout << "Top element: " << s3.peek() << endl;

    cout << "Current size: " << s3.size() << endl;
    cout << "Popped element: " << s3.pop() << endl;
    cout << "Popped element: " << s3.pop() << endl;
    cout << "Popped element: " << s3.pop() << endl;
    cout << "Popped element: " << s3.pop() << endl;
    cout << "Current size: " << s3.size() << endl;


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