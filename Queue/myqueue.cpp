#include<iostream>

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
    cout << "\n######  End of Program  ######\n" << endl;
    return 0;
}

/*********************************************************/
/*********************************************************/