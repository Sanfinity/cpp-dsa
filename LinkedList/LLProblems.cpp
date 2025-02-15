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

    void setHead(Node<T>* newHead) {
        head = newHead;
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

    void deleteHead() {
        if (!head) {
            cout << "Empty List!" << endl;
            return;
        }
        Node<T>* tempNode = head->next;
        head->data = tempNode->data;
        head->next = tempNode->next;
        delete tempNode;
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

    void mergeSortedLists(Node<T>* head1, Node<T>* head2) {
        Node<T>* dummyNode = new Node<int>(-1);
        Node<T>* tempNode = dummyNode;
        cout << "Merged Sorted List: ";

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tempNode->next = head1;
                head1 = head1->next;
            }
            else {
                tempNode->next = head2;
                head2 = head2->next;
            }
            tempNode = tempNode->next;
            cout << tempNode->data << " ";
        }

        if (head1) {
            tempNode->next = head1;
        }
        if (head2) {
            tempNode->next = head2;
        }
        cout << tempNode->next->data << " " << endl;
    }

    void printCommonElements(Node<T>* head1, Node<T>* head2) {
        while (head1 && head2) {
            if (head1->data < head2->data) {
                head1 = head1->next;
            }
            else if (head1->data == head2->data) {
                cout << head1->data << endl;
                head1 = head1->next;
                head2 = head2->next;
            }
            else {
                head2 = head2->next;
            }
        }
    }

    void reverseInPairs() {
        Node<T>* prev = NULL;
        Node<T>* current = head;
        head = head->next;

        while (current && current->next) {
            auto nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = current;
            if (prev) {
                prev->next = nextNode;
            }
            prev = current;
            current = current->next;
        }
    }

    Node<T>* reverseList(Node<T>* head) {
        if (!head) {
            return nullptr;
        }
        Node<T>* prev = nullptr;
        Node<T>* tempNode = head;
        while (tempNode) {
            auto nextNode = tempNode->next;
            tempNode->next = prev;
            prev = tempNode;
            tempNode = nextNode;
        }
        return prev;
    }

    void checkPalindrome() {
        auto fast = head;
        auto slow = head;
        bool isOdd{ false };
        while (fast) {
            if (!fast->next) {
                isOdd = true;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        auto secondHead = reverseList(slow);
        auto firstHalf = head;
        auto secondHalf = secondHead;
        bool isPal = true;
        while (secondHalf) {
            if (secondHalf->data != firstHalf->data) {
                isPal = false;
                break;
            }
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }

        if (isPal) {
            cout << "The given linked list is a palindrome!" << endl;
        }
    }

    Node<T>* ReverseKNodes(Node<T>* phead, int k) {
        if (!phead || k <= 1) return phead;

        int count{ 0 };
        Node<T>* prev = nullptr;
        Node<T>* current = phead;
        Node<T>* next = nullptr;

        // check for atleast k elements in the list
        auto temp = phead;
        while (temp && count < k) {
            count++;
            temp = temp->next;
        }

        if (count < k) {
            cout << "Increase the number of elements and try again!";
            return phead;
        }

        // reverse the first k nodes now
        count = 0;
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next) {
            phead->next = ReverseKNodes(next, k);
        }

        return prev;
    }

    void sortEvenOdd() {
        if (!head) {
            cout << "Empty List!";
            return;
        }
        Node<T>* EvenHead = new Node<T>(-1);
        auto EvenTraverser = EvenHead;
        Node<T>* OddHead = new Node<T>(-1);
        Node<T>* OddTraverser = OddHead;
        auto temp = head;
        while (temp) {
            if (temp->data % 2 == 0) {
                EvenTraverser->next = temp;
                EvenTraverser = EvenTraverser->next;
            }
            else {

                OddTraverser->next = temp;
                OddTraverser = OddTraverser->next;
            }
            temp = temp->next;
        }
        EvenTraverser->next = OddHead->next;
        head = EvenHead->next;
        delete EvenHead;
        delete OddHead;
    }

    void findModularNode(int k) {
        if (!head) {
            cout << "Empty List!";
            return;
        }
        auto temp = head;
        Node<T>* modularNode = nullptr;
        int count{ 1 }, modularNodepose{ 0 };
        while (temp) {
            if (temp->data % k == 0) {
                modularNode = temp;
                modularNodepose = count;
            }
            temp = temp->next;
            count++;
        }
        cout << "The modular node is data: " << modularNode->data
            << " ptr: " << reinterpret_cast<uintptr_t>(modularNode)
            << " position: " << modularNodepose << endl;
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

// Question: Given two sorted linked lists, how to merge them into the third list in sorted order
// Solution: using pointer comparison
void problem7() {
    LinkedList<int> ll;
    // Creating first sorted linked list: 1 -> 3 -> 5
    Node<int>* head1 = new Node<int>(1);
    head1->next = new Node<int>(3);
    head1->next->next = new Node<int>(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    Node<int>* head2 = new Node<int>(2);
    head2->next = new Node<int>(4);
    head2->next->next = new Node<int>(6);

    // Merging the two sorted lists
    ll.mergeSortedLists(head1, head2);
}

// Question: Reverse linked list in pairs
// Solution: using simple pointer iterations
void problem8() {
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
    ll.reverseInPairs();
    ll.display();
}

// Question: Given two sorted linked lists, print the common elements in it
// Solution: using pointer comparison
void problem9() {
    LinkedList<int> ll;
    // Creating first sorted linked list: 1 -> 3 -> 5 -> 8
    Node<int>* head1 = new Node<int>(1);
    head1->next = new Node<int>(3);
    head1->next->next = new Node<int>(5);
    head1->next->next->next = new Node<int>(8);

    // Creating second sorted linked list: 1 -> 2 -> 5 -> 6
    Node<int>* head2 = new Node<int>(1);
    head2->next = new Node<int>(2);
    head2->next->next = new Node<int>(5);
    head2->next->next->next = new Node<int>(6);

    // Merging the two sorted lists
    ll.printCommonElements(head1, head2);
}

// Question: Check if the linked list is palindrome or not
// Solution: Split and compare method
void problem10() {
    LinkedList<int> ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.checkPalindrome();
    //ll.display();
}

// Question: For a given k value (k>0) reverse blocks of k nodes in a list.
// Solution: Using the same swapping nodes in a linked list concept
void problem11() {
    LinkedList<int> ll;
    ll.insert(9);
    ll.insert(8);
    ll.insert(7);
    ll.insert(6);
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    //cout << "Enter the value for k: ";
    //int k;
    //cin >> k;
    auto newHead = ll.ReverseKNodes(ll.getHead(), 3);
    ll.setHead(newHead);
    ll.display();
}

// Iterative function to solve Josephus Problem
int josephusIterative(int n, int k) {
    int result = 0; // When there's only one person left, they are at position 0 (0-based)
    for (int i = 2; i <= n; i++) {
        cout << "For i = " << i << ": result = (" << result << " + " << k << ") % " << i << " = " << (result + k) % i << endl;
        result = (result + k) % i; // Update the safe position
    }
    return result + 1; // Convert from 0-based to 1-based
}

int JosephusLLSimulate(int n, int k) {
    Node<int>* head = new Node<int>(1);
    Node<int>* prev = head;
    for (int i = 2; i <= n; i++) {
        prev->next = new Node<int>(i);
        prev = prev->next;
    }
    prev->next = head;

    Node<int>* current = head;
    while (current->next != current) {
        for (int i = 1; i < k - 1; i++) {
            current = current->next;
        }
        auto toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;

        current = current->next;
    }

    // Don't forget to delete the list at the end
    int survivor = current->data;
    delete current;
    return survivor;
}

// Question: Josephus Circle: There are N people standing in a circle. 
// Every k-th person is eliminated until only one person remains. 
// Find the position of that last person (1-based index).
// Solution: Using Circular Linked List.
void problem12() {
    cout << "Final Result via iterative method: " << josephusIterative(7, 2) << endl;
    cout << "Final Result via circular linked list method: " << JosephusLLSimulate(7, 2) << endl;
}

// Question: Given a pointer to a node in a singly linked list, 
// delete that node from the linked list.
// Solution: Think out of the box and use what you already have.
void problem13() {
    LinkedList<int> ll;
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.deleteHead();
    ll.display();
}

// Question: Given a linked list with even and odd numbers, 
// create an algorithm for making changes to the list 
// in such a way that all even numbers appear at the beginning.
// Solution: Using splitting logic in linked list.
void problem14() {
    LinkedList<int> ll;
    ll.insert(9);
    ll.insert(8);
    ll.insert(7);
    ll.insert(6);
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.sortEvenOdd();
    ll.display();
}

// Question: Finding the Modular Node in a Linked List
// Solution: Given a singly linked list and an integer k, 
// find the last node in the list whose position (1-based index) is divisible by k.
void problem15() {
    LinkedList<int> ll;
    ll.insert(9);
    ll.insert(8);
    ll.insert(7);
    ll.insert(6);
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    ll.findModularNode(2);
}

/*****************************************************/
/*****************************************************/

int main() {
    cout << "###### Start of Program ######\n" << endl;
    problem15();
    cout << "\n######  End of Program  ######" << endl;
    return 0;
}

/*****************************************************/
/*****************************************************/
