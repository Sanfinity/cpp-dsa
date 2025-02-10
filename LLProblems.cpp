//#include <iostream>
//using namespace std;
//
//int main() {
//    cout << "### Start of Program ###" << endl;
//    return 0;
//}

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

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    Node<T>* getHead() {
        return head;
    }

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

    void printFromEnd(Node<T>* node) {
        if (!node) {
            return;
        }
        printFromEnd(node->next);
        cout << node->data << " ";
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

    void reverseLL() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;

        while (current) {
            Node<T>* tempNode = current->next;
            current->next = prev;
            prev = current;
            current = tempNode;
        }
        head = prev;
    }

    void findMiddleSimple() {
        Node<T>* tempNode = head;
        auto len = 0;
        while (tempNode) {
            tempNode = tempNode->next;
            len++;
        }
        tempNode = head;
        for (int i = 0; i < len / 2 - 1; i++) {
            tempNode = tempNode->next;
        }
        if (!tempNode || !tempNode->next) {
            cout << "Error occured!" << endl;
            return;
        }
        if (len % 2 == 0) {
            cout << "Middle Elements is " << tempNode->data << " and " << tempNode->next->data << endl;
        }
        else {
            cout << "Middle Elements is " << tempNode->next->data << endl;
        }
    }

    void findMiddleTwoPointer() {
        Node<T>* fast = head;
        Node<T>* slow = head;
        bool isEven{ false };
        while (fast->next) {
            if (!fast->next->next) {
                isEven = true;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        if (isEven) {
            cout << "Middle Elements is " << slow->data << " and " << slow->next->data << endl;
        }
        else {
            cout << "Middle Elements is " << slow->data << endl;
        }
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


// Question: Reverse a singly linked list
void problem3() {
    LinkedList<int> ll;
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.reverseLL();
    ll.display();
}

// Function to find intersection using stacks
void findIntersection(Node<int>* head1, Node<int>* head2) {
    Node<int>* tempNode = head1;
    stack<Node<int>*> list1;
    while (tempNode) {
        list1.push(tempNode);
        tempNode = tempNode->next;
    }
    tempNode = head2;
    stack<Node<int>*> list2;
    while (tempNode) {
        list2.push(tempNode);
        tempNode = tempNode->next;
    }
    tempNode = nullptr;
    while (!list1.empty() && !list2.empty()) {
        auto list1Node = list1.top();
        auto list2Node = list2.top();
        if (list1Node != list2Node && tempNode)
        {
            cout << "The Intersection is " << tempNode->data << endl;
            return;
        }
        tempNode = list1Node;
        list1.pop();
        list2.pop();
    }
}

// Time Complexity = O(max(m,n))
void findIntersectionImprovedPerformance(Node<int>* head1, Node<int>* head2) {
    int lenList1{ 0 }, lenList2{ 0 };
    Node<int>* tempNode = head1;
    while (tempNode) {
        lenList1++;
        tempNode = tempNode->next;
    }
    tempNode = head2;
    while (tempNode) {
        lenList2++;
        tempNode = tempNode->next;
    }
    auto diff = abs(lenList1 - lenList2);

    Node<int>* first = head1;
    Node<int>* second = head2;

    if (lenList1 > lenList2) {
        for (int i = 0; i < diff;i++) {
            first = first->next;
        }
    }
    else {
        for (int i = 0; i < diff;i++) {
            second = second->next;
        }
    }

    while (first && second && first->data != second->data) {
        first = first->next;
        second = second->next;
    }

    cout << "The intersecting element is " << first->data << endl;
}

// Question: Find the intersection point of two singly linked lists using stacks
// Solution: Using two stack & two pointer approach
void problem4() {
    Node<int>* common = new Node<int>(6);
    common->next = new Node<int>(7);
    common->next->next = new Node<int>(8);

    Node<int>* head1 = new Node<int>(1);
    head1->next = new Node<int>(2);
    head1->next->next = new Node<int>(3);
    head1->next->next->next = common;

    Node<int>* head2 = new Node<int>(4);
    head2->next = new Node<int>(5);
    head2->next->next = common;

    findIntersection(head1, head2);
    findIntersectionImprovedPerformance(head1, head2);
}

// Question: Find the middle element of the list
// Solution: Using simple O(n + n/2) way and two pointer O(n) way
void problem5() {
    LinkedList<int> ll;
    //ll.insert(8);
    ll.insert(7);
    ll.insert(6);
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.findMiddleSimple();
    ll.findMiddleTwoPointer();
}

// Question: Print the LL from the end
// Solution: Using recursion
void problem6() {
    LinkedList<int> ll;
    ll.insert(8);
    ll.insert(7);
    ll.insert(6);
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.printFromEnd(ll.getHead());
    cout << endl;
}

/*****************************************************/
/*****************************************************/

int main() {
    cout << "### Start of Program ###" << endl;
    problem6();
    cout << "### End of Program ###" << endl;
    return 0;
}

/*****************************************************/
/*****************************************************/
