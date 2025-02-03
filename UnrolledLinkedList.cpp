#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    Node<T>* next;
    T data;

    Node(T inputData) : next(nullptr), data(inputData) {}
};

template<typename T>
class Block {
public:
    Block<T>* next;
    Node<T>* head;
    int nodeCount;
    static const int MAX_NODES = 3;

    Block() : next(nullptr), head(nullptr), nodeCount(0) {}
};

template<typename T>
class UnrolledLL {
private:
    Block<T>* blockHead;

    void shift(Block<T>* block) {
        if (block->nodeCount > Block<T>::MAX_NODES) {
            Node<T>* temp = block->head;
            for (int i = 0; i < Block<T>::MAX_NODES / 2; i++) {
                temp = temp->next;
            }

            Block<T>* newBlock = new Block<T>();
            newBlock->next = block->next;
            block->next = newBlock;
            newBlock->head = temp->next;
            temp->next = nullptr;

            newBlock->nodeCount = block->nodeCount - (Block<T>::MAX_NODES / 2 + 1);
            block->nodeCount = Block<T>::MAX_NODES / 2 + 1;
        }
    }

public:
    UnrolledLL() : blockHead(nullptr) {}

    ~UnrolledLL() {
        Block<T>* currentBlock = blockHead;
        while (currentBlock) {
            Node<T>* current = currentBlock->head;
            while (current) {
                Node<T>* next = current->next;
                delete current;
                current = next;
            }
            Block<T>* nextBlock = currentBlock->next;
            delete currentBlock;
            currentBlock = nextBlock;
        }
    }

    void display() {
        if (!blockHead) {
            cout << "Empty List!" << endl;
            return;
        }

        Block<T>* temp = blockHead;
        cout << "List Content: {" << endl;
        while (temp) {
            Node<T>* tempNode = temp->head;
            for (int i = 0; i < temp->nodeCount; i++) {
                cout << tempNode->data << " ";
                tempNode = tempNode->next;
            }
            cout << endl;
            temp = temp->next;
        }
        cout << "}" << endl;
    }

    void insert(T data, int position) {
        Node<T>* newNode = new Node<T>(data);
        if (!blockHead) {
            Block<T>* newBlock = new Block<T>();
            newBlock->head = newNode;
            newBlock->nodeCount++;
            blockHead = newBlock;
        }
        else {
            Block<T>* currentBlock = blockHead;
            int currentPosition = 0;

            while (currentBlock->next && currentPosition + currentBlock->nodeCount < position) {
                currentPosition += currentBlock->nodeCount;
                currentBlock = currentBlock->next;
            }

            if (position == 0) {
                newNode->next = currentBlock->head;
                currentBlock->head = newNode;
                currentBlock->nodeCount++;
            }
            else {
                Node<T>* temp = currentBlock->head;
                for (int i = 1; i < position - currentPosition; i++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                currentBlock->nodeCount++;
            }

            shift(currentBlock);
        }
    }
};

int ullmain() {
    cout << "### Program Started ###" << endl;
    UnrolledLL<int> ull;
    ull.insert(2, 0);
    ull.insert(3, 1);
    ull.insert(4, 2);
    ull.insert(5, 3);
    ull.insert(6, 4);
    ull.display();
    return 0;
}
