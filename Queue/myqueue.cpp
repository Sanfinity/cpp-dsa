#include<iostream>
#include<queue>

using namespace std;

class queueUsingArray {
private:
    int front, rear, capacity;
    int* arr;

public:
    queueUsingArray(int size) {
        arr = new int[size];
        capacity = size;
        front = rear = -1;
    }

    ~queueUsingArray() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is already full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is already empty" << endl;
            return -1;
        }

        auto data = arr[front];

        if (rear == front) {
            rear = front = -1;
        }
        else {
            front++;
        }

        return data;
    }

    int getFront() {
        return arr[front];
    }

    int getRear() {
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Content of Queue is [ ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
};

/*********************************************************/
/*********************************************************/

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T input) {
        data = input;
        next = nullptr;
    }
};

template <typename T>
class QueueUsingLL {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    QueueUsingLL() :front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(T input) {
        Node<T>* newNode = new Node<T>(input);
        if (rear == nullptr) {
            rear = newNode;
            front = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "List is already empty!" << endl;
        }
        Node<T>* deleteNode = front;
        front = front->next;
        if (front == nullptr) front = rear = nullptr;
        cout << "Element deleted is " << deleteNode->data << endl;
        delete deleteNode;
    }

    int getFront() {
        return isEmpty() ? -1 : front->data;
    }

    int getRear() {
        return isEmpty() ? -1 : rear->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        Node<T>* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    cout << "\n###### Start of Program ######\n" << endl;
    queueUsingArray q(6);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    cout << "Front: " << q.getFront() << ", Rear: " << q.getRear() << endl;

    cout << "#####" << endl;

    QueueUsingLL<int> q2;
    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);
    q2.enqueue(50);
    q2.enqueue(60);
    q2.enqueue(70);
    q2.enqueue(80);
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.display();
    cout << "Front: " << q2.getFront() << ", Rear: " << q2.getRear() << endl;

    cout << "#####" << endl;
    queue<int> q3;
    q3.push(1);
    q3.push(2);
    q3.push(3);
    q3.push(4);
    q3.push(5);
    q3.push(6);
    cout << "Queue size: " << q3.size() << endl;
    for (int i = 0; i < 3;i++) {
        cout << "Pop element: front -> " << q3.front() << " back -> " << q3.back() << endl;
        q3.pop();
    }

    cout << "Queue size: " << q3.size() << endl;

    cout << "\n######  End of Program  ######\n" << endl;
    return 0;
}

/*********************************************************/
/*********************************************************/