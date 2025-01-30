#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    Node<T>* next;
    T data;

    Node(int value) : next(nullptr), data(value) {}
};

template<typename T>
class Block {
public:
    Block<T>* next;
    Node<T>* head;
    int nodeCount;

    Block() : next(nullptr), head(nullptr), nodeCount(0) {}
};

template<typename T>
class UnrolledLL {
private:
    Block<T>* blockHead;

public:
    void display() {
        if (!blockHead) {
            cout << "Empty List!" << endl;
            return;
        }

        Block<T>* temp = blockHead;
        cout << "List Content: {";
        while (temp) {
            Node<T>* tempNode = temp->head;
            for (int i = 0; i < temp->nodeCount;i++) {
                cout << tempNode->data << " ";
                tempNode = tempNode->next;
            }
            cout << endl;
            temp = temp->next;
        }
        cout << "}" << endl;
    }

    void insert(T data, int position) {
        Node<T>* newNode = new Node(data);
        if (!blockHead) {
            Block<T>* newBlock = new Block<T>();
            newBlock->head = newNode;
            blockHead = newBlock;
        }
        else {
            if (position == 0) {
                newNode->next = blockHead->head;
                blockHead->head = newNode;
                blockHead->nodeCount++;
                shift(blockHead);
            }
            else {
                Block<T>* tempBlock = new Block<T>();
                Node<T>* tempNode = temp->head;

                searchElement(position, &tempBlock, &tempNode);
            }
        }
    }
};

int main() {
    cout << "### Program Started ###" << endl;
    return 0;
}