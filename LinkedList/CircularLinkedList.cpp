#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next = nullptr;

    Node(T data) {
        this->data = data;
    }
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head = nullptr;

public:
    void InsertAtFirst(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* tempNode = head;
            newNode->next = head;
            while (tempNode->next != head) {
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
            head = newNode;
        }
    }

    void InsertAtEnd(T data) {
        if (!head) {
            InsertAtFirst(data);
            return;
        }

        Node<T>* tempNode = head;
        while (tempNode->next != head) {
            tempNode = tempNode->next;
        }

        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        tempNode->next = newNode;
    }

    void InsertAtPosition(T data, int position) {
        if (position == 1) {
            InsertAtFirst(data);
            return;
        }
        if (!head) {
            cout << "Error: Position out of index" << endl;
            return;
        }

        Node<T>* tempNode = head;
        int counter{ 1 };
        do {
            if (counter == position - 1) {
                Node<T>* newNode = new Node<T>(data);
                newNode->next = tempNode->next;
                tempNode->next = newNode;
                return;
            }
            tempNode = tempNode->next;
            counter++;
        } while (tempNode != head);
        cout << "Error: Position out of index" << endl;
    }

    void DeleteAtFirst() {
        if (!head) {
            cout << "Empty List!" << endl;
        }
        else if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* tempNode = head;
            while (tempNode->next != head) {
                tempNode = tempNode->next;
            }
            Node<T>* deleteNode = head;
            tempNode->next = head->next;
            head = head->next;
            delete deleteNode;
        }
    }

    void DeleteAtEnd() {
        if (!head) {
            cout << "Empty List!" << endl;
        }
        else if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* tempNode = head;
            while (tempNode->next->next != head) {
                tempNode = tempNode->next;
            }
            Node<T>* deleteNode = tempNode->next;
            tempNode->next = head;
            delete deleteNode;
        }
    }


    void DeleteAtPosition(int position) {
        if (!head) {
            cout << "Empty List!" << endl;
        }
        else if (position == 1) {
            DeleteAtFirst();
        }
        else if (position > 1) {
            Node<T>* tempNode = head;
            int counter{ 1 };
            while (tempNode->next != head) {
                if (counter == position - 1) {
                    Node<T>* deleteNode = tempNode->next;
                    tempNode->next = tempNode->next->next;
                    delete deleteNode;
                }
                tempNode = tempNode->next;
                counter++;
            }
        }
        else {
            cout << "Invalid Position" << endl;
        }
    }

    void Display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node<T>* tempNode = head;
        cout << "List Content : [ ";
        do {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        } while (tempNode != head);
        cout << "]" << endl;
    }
};

int CircularLLTrail() {
    cout << "### Start of Program ###" << endl;
    CircularLinkedList<int> cll;
    cll.InsertAtFirst(1);
    cll.InsertAtEnd(4);
    cll.InsertAtFirst(2);
    cll.InsertAtEnd(5);
    cll.InsertAtFirst(3);
    cll.InsertAtPosition(6, 4);
    cll.InsertAtPosition(7, 1);
    cll.InsertAtPosition(8, 8);
    cll.InsertAtPosition(9, 10);
    cll.Display();
    //cll.DeleteAtFirst();
    //cll.DeleteAtFirst();
    //cll.DeleteAtEnd();
    //cll.DeleteAtEnd();
    cll.DeleteAtPosition(1);
    cll.DeleteAtPosition(2);
    cll.DeleteAtPosition(3);
    cll.DeleteAtPosition(5);
    cll.Display();

    return 0;
}