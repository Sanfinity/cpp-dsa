//#include <iostream>
//using namespace std;
//
//int main() {
//    cout << "### Start of Program ###" << endl;
//    return 0;
//}

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    Node<T>* next;
    T data;
    Node(T value) : next(nullptr), data(value) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(T inputData) {
        Node<T>* newNode = new Node<T>(inputData);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void display() {
        if (!head) {
            cout << "Empty List!" << endl;
            return;
        }
        Node<T>* tempNode = head;
        cout << "List content: [ ";
        while (tempNode) {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << "]" << endl;
    }

    void findNthNodeFromEnd(int n) {
        Node<T>* fast = head;
        Node<T>* slow = head;
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) {
                cout << "Error: List length less than n!" << endl;
                return;
            }
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow) {
            cout << n << "th element is " << slow->data << endl;
        }
        else {
            cout << "Error: List length less than n!" << endl;
        }
    }

    void findLoops() {
        Node<T>* fast = head;
        Node<T>* slow = head;
        int counter{ 1 };
        while (slow) {
            if (fast == slow && counter != 1) {
                break;
            }
            slow = slow->next;
            if (!fast->next) {
                cout << "No loop found!" << endl;
                return;
            }
            fast = fast->next->next;
            counter++;
        }
        slow = head;
        counter = 0;
        cout << "Stage 1 is done" << endl;
        while (fast != slow && slow && fast) {
            fast = fast->next;
            slow = slow->next;
            counter++;
        }
        cout << "Loop found at " << counter << "th Node!" << endl;
    }

    void createLoopAt(int position) {
        if (!head) {
            return;
        }
        Node<T>* tempNode = head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        Node<T>* loopNode = head;
        for (int i = 0;i < position; i++) {
            if (!loopNode->next) {
                cout << "Error: out of index" << endl;
                return;
            }
            loopNode = loopNode->next;
        }
        tempNode->next = loopNode;
    }
};


// Question: Find the nth node from the end of a linked list in the most effective way possible.
// Solution: To find the nth node from the end of a singly linked list efficiently, 
// the most effective approach is to use the two-pointer technique (also known as the fast and slow pointer approach). 
// This method allows you to find the desired node in just one pass over the list, 
// making it an O(n) time complexity solution with O(1) space complexity.
void problem1() {
    LinkedList<int> ll;
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.findNthNodeFromEnd(1);
}

// Question: Find whether there is any loop in the linked list or not.
// Solution: Floyd’s cycle finding algorithm or Hare-Tortoise algorithm is a pointer algorithm that 
// uses only two pointers, moving through the sequence at different speeds. This algorithm is used to 
// find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. 
// The faster one is called the fast pointer and the other one is called the slow pointer.
void problem2() {
    LinkedList<int> ll;
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.createLoopAt(2);
    ll.findLoops();
}

int main() {
    cout << "### Start of Program ###" << endl;
    problem2();
    return 0;
}