#include <iostream>
#include <cstdint>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* both;

    Node(T value) : data(value), both(nullptr) {}
};

template <typename T>
class XorLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* XOR(Node<T>* nodeA, Node<T>* nodeB) {
        return reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(nodeA) ^ reinterpret_cast<uintptr_t>(nodeB));
    }
public:
    XorLinkedList() : head(nullptr), tail(nullptr) {}

    void AddAtStart(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->both = XOR(nullptr, head);
            head->both = XOR(newNode, head->both);
            head = newNode;
        }
    }

    void AddAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->both = XOR(tail, nullptr);
            tail->both = XOR(XOR(tail->both, nullptr), newNode);
            tail = newNode;
        }
    }

    void DeleteAtStart() {
        if (!head) {
            cout << "Empty List!" << endl;
        }
        else {
            Node<T>* deleteNode = head;
            Node<T>* next = XOR(nullptr, head->both);
            next->both = XOR(deleteNode, next->both);
            head = next;
            delete deleteNode;
        }
    }

    void DeleteAtTail() {
        if (!head) {
            cout << "Empty List!" << endl;
        }
        else {
            Node<T>* deleteNode = tail;
            Node<T>* next = XOR(nullptr, tail->both);
            next->both = XOR(deleteNode, next->both);
            tail = next;
            delete deleteNode;
        }
    }

    void Traversal(bool rev = false) {
        if (!head) {
            cout << "Empty List!" << endl;
        }
        else {
            Node<T>* current = nullptr;
            if (rev) {
                current = tail;
            }
            else {
                current = head;
            }
            Node<T>* prev = nullptr;
            cout << "List Data: [ ";
            while (current) {
                cout << current->data << " ";
                Node<T>* dummy = XOR(prev, current->both);
                prev = current;
                current = dummy;
            }
            cout << "]" << endl;
        }
    }
};


int main() {
    cout << "### Start of Program ###" << endl;
    XorLinkedList<int> xll;
    xll.AddAtStart(1);
    xll.AddAtStart(2);
    xll.AddAtStart(3);
    xll.AddAtEnd(4);
    xll.AddAtEnd(5);
    xll.Traversal();
    xll.DeleteAtStart();
    xll.DeleteAtTail();
    xll.Traversal();
    xll.Traversal(1);

    return 0;
}