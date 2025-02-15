#include <iostream>

using namespace std;

struct Node {
	int integerValue;
	Node* next;
	Node* prev;
};

class SinglyLinkedList {
private:
	Node* head;

public:
	SinglyLinkedList() :head(NULL) {}

	Node* CreateNewNode(int data) {
		Node* newNode = new Node;
		newNode->integerValue = data;
		newNode->next = NULL;
		return newNode;
	}

	void InsertAtStart(int data) {
		Node* newNode = CreateNewNode(data);
		newNode->next = head;
		head = newNode;
	}

	void InsertAtEnd(int data) {
		Node* newNode = CreateNewNode(data);
		if (!head) {
			head = newNode;
		}
		else {
			Node* tempNode = head;
			while (tempNode->next) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
	}

	void InsertAtPosition(int data, int position) {
		if (position < 1) {
			cout << "Invalid position please Try with a valid position" << endl;
			return;
		}
		else if (position == 1) {
			InsertAtStart(data);
		}
		else {
			Node* newNode = CreateNewNode(data);
			Node* tempNode = head;
			int itr = 1;
			bool NodeAddedSuccess{ false };
			while (tempNode) {
				if (itr == position - 1) {
					newNode->next = tempNode->next;
					tempNode->next = newNode;
					NodeAddedSuccess = true;
				}
				itr++;
				tempNode = tempNode->next;
			}
			if (!NodeAddedSuccess) {
				cout << "Invalid position, please verify and try again" << endl;
			}

		}
	}

	void DeleteElementAtStart() {
		if (!head) {
			cout << "List is empty! nothing to delete here";
			return;
		}
		Node* tempNode = head;
		head = tempNode->next;
		delete tempNode;
	}

	void DeleteElementAtEnd() {
		if (!head) {
			cout << "List is empty! nothing to delete here";
			return;
		}

		if (!head->next) {
			delete head;
			head = NULL;
			return;
		}

		Node* tempNode = head;
		while (tempNode->next->next) {
			tempNode = tempNode->next;
		}
		delete tempNode->next;
		tempNode->next = nullptr;
	}

	void DeleteElementAtPosition(int position) {
		if (position < 1) {
			cout << "Invalid position please Try with a valid position" << endl;
			return;
		}

		if (position == 1) {
			DeleteElementAtStart();
			return;
		}

		Node* tempNode = head;
		bool NodeAddedSuccess{ false };
		int itr{ 1 };
		while (tempNode->next) {
			if (itr == position - 1) {
				Node* deleteNode = tempNode->next;
				tempNode->next = tempNode->next->next;
				delete deleteNode;
				NodeAddedSuccess = true;
				return;
			}
			itr++;
			tempNode = tempNode->next;
		}
		if (!NodeAddedSuccess) {
			cout << "Invalid position " << position << ", Please Try again!" << endl;
		}
	}

	void DeleteLinkedList() {
		Node* traversalNode = head;
		while (traversalNode) {
			Node* tempNode = traversalNode;
			traversalNode = traversalNode->next;
			delete tempNode;
		}
		head = nullptr;
	}

	void PrintList() {
		cout << "\nPrinting List" << endl;
		if (!head) {
			cout << "No element added to the list, check and try again later!"
				<< endl;
			return;
		}

		Node* tempNode = head;
		cout << "Data present: ";
		while (tempNode) {
			cout << tempNode->integerValue << " -> ";
			tempNode = tempNode->next;
		}
		cout << "Null" << endl;
		delete tempNode;
	}
};

class DoublyLinkedList {
private:
	Node* head = nullptr;

public:
	Node* CreateDoubleLinkNode(int data) {
		Node* newNode = new Node;
		newNode->integerValue = data;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		return newNode;
	}


	void InsertAtStart(int data) {
		Node* newNode = CreateDoubleLinkNode(data);
		if (!head) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void InsertAtEnd(int data) {
		Node* newNode = CreateDoubleLinkNode(data);
		if (!head) {
			head = newNode;
		}
		else {
			Node* tempNode = head;
			while (tempNode->next) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
			newNode->prev = tempNode;
		}
	}

	void InsertAtPosition(int data, int position) {
		if (position < 1) {
			cout << "Position should be greater than 1";
			return;
		}

		if (position == 1) {
			InsertAtStart(data);
			return;
		}

		Node* tempNode = head;
		int counter{ 1 };
		while (tempNode) {
			if (counter == position - 1) {
				Node* newNode = CreateDoubleLinkNode(data);
				if (tempNode->next != nullptr) {
					tempNode->next->prev = newNode;
				}
				newNode->next = tempNode->next;
				newNode->prev = tempNode;
				tempNode->next = newNode;
				return;
			}
			tempNode = tempNode->next;
			counter++;
		}
		cout << "Position out of bound" << endl;
	}

	void DeleteElementAtFirst() {
		if (!head) {
			cout << "No element in the list already!" << endl;
			return;
		}

		Node* tempNode = head;
		head = head->next;
		head->prev = nullptr;
		delete tempNode;
	}

	void DeleteElementAtEnd() {
		if (!head) {
			cout << "No element in the list already!" << endl;
			return;
		}
		Node* tempNode = head;

		if (tempNode->next == nullptr) {
			head = nullptr;
			delete tempNode;
			return;
		}

		while (tempNode->next) {
			tempNode = tempNode->next;
		}
		tempNode->prev->next = nullptr;
		delete tempNode;
	}

	void DeleteElementAtPosition(int position) {
		if (!head) {
			cout << "No element in the list already!" << endl;
			return;
		}

		if (position < 1) {
			cout << "Position should be greater than 1";
			return;
		}

		if (position == 1) {
			DeleteElementAtFirst();
			return;
		}

		Node* tempNode = head;
		int counter = 1;

		while (tempNode) {
			if (counter == position) {
				if (tempNode->prev != nullptr) {
					tempNode->prev->next = tempNode->next;
				}
				if (tempNode->next) {
					tempNode->next->prev = tempNode->prev;
				}
				delete tempNode;
				return;
			}
			tempNode = tempNode->next;
			counter++;
		}
		cout << "Invalid position values!" << endl;
	}

	void ForwardPrint() {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}

		Node* tempNode = head;
		cout << "List Content: ";
		while (tempNode) {
			cout << tempNode->integerValue << " -> ";
			tempNode = tempNode->next;
		}
		cout << "NULL" << endl;
	}

	void ReversePrint() {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}

		Node* tempNode = head;
		cout << "List Content: ";
		while (tempNode->next) {
			tempNode = tempNode->next;
		}

		while (tempNode) {
			cout << tempNode->integerValue << " -> ";
			tempNode = tempNode->prev;
		}
		cout << "NULL" << endl;
	}

	void DeleteList() {
		if (!head) {
			cout << "No element in the list already!" << endl;
			return;
		}
		Node* tempNode = head;
		while (tempNode) {
			Node* deleteNode = tempNode;
			tempNode = tempNode->next;
			delete deleteNode;
		}
		head = nullptr;
	}
};

int LLmain() {
	cout << "Linked List!" << endl;
	//SinglyLinkedList MySingleLL;
	//MySingleLL.InsertAtStart(2);
	//MySingleLL.InsertAtStart(3);
	//MySingleLL.InsertAtStart(4);
	//MySingleLL.InsertAtEnd(5);
	//MySingleLL.InsertAtPosition(6, 5);
	//MySingleLL.PrintList();
	//MySingleLL.DeleteElementAtPosition(5);
	//MySingleLL.PrintList();
	//MySingleLL.DeleteLinkedList();
	//MySingleLL.PrintList();

	DoublyLinkedList MyDoublyLL;
	MyDoublyLL.InsertAtStart(2);
	MyDoublyLL.InsertAtStart(3);
	MyDoublyLL.InsertAtStart(4);
	MyDoublyLL.InsertAtPosition(7, 4);
	MyDoublyLL.InsertAtPosition(8, 5);
	MyDoublyLL.ForwardPrint();
	MyDoublyLL.DeleteElementAtFirst();
	MyDoublyLL.ForwardPrint();
	MyDoublyLL.DeleteElementAtEnd();
	MyDoublyLL.ForwardPrint();
	MyDoublyLL.DeleteElementAtPosition(1);
	MyDoublyLL.ForwardPrint();
	MyDoublyLL.DeleteList();

	MyDoublyLL.InsertAtEnd(5);
	MyDoublyLL.InsertAtEnd(6);
	MyDoublyLL.ReversePrint();



	cout << "\n============= END OF PROGRAM =============" << endl;

	return 0;
}