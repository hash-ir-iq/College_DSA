#include<iostream>
using namespace std;

template <typename T> class LinkedList {

private:

	struct Node {
	public:

		Node() {
			next = NULL;
		}
		Node(T d, Node* n=0) {
			data = d;
			next = n;
		}

		T data;
		Node* next;
	};


public:
	Node* head;

	LinkedList() {
		head = NULL;
	}

	~LinkedList() {
		Node* temp = head;
		while (temp) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	
	void insertAtStart(T const element) {
		Node* temp = head;
		head = new Node(element);
		head->next = temp;
	}

	void insertAtEnd(T const element) {
		Node* temp = head;
		while (temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next = new Node(element);

	}

	void print() const {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	bool search(T const& element) const {

		Node* temp = head;
		while (temp->next) {
			if (temp->data == element) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool isEmpty() const {
		if (head)
			return false;
		return true;
	}

	bool insertBefore(T const v1, T const v2) {

		Node* temp1 = head;
		Node* temp2 = head->next;
		while (temp1) {
			if (temp1->data == v2) {
				if (temp1 == head) {
					insertAtStart(v1);
					return true;
				}
				temp2 = new Node(v1, temp1);
				return true;
			}
			temp2 = temp1;
			temp1 = temp1->next;
		}
		return false;
	}

	void DeleteAtStart() {

		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void deleteDuplicates() {
		Node* temp1 = head;
		while (temp1) {

			Node* temp2 = temp1->next;
			Node* temp4 = temp1;

			while (temp2) {
				if (temp1 == temp2) {
					temp4->next = temp2;
					delete temp2;
				}
				temp4 = temp2;
				temp2 = temp2->next;		
			}
			temp1 = temp1->next;
		}
	}

	// ============= TASK 2 ===============================
	void deleteRange(T start, T End) {
		Node* temp = head;
		Node* temp2 = head;
		while (temp->next) {

			if (temp->data >= start && temp->data <= End) {
				temp2->next = temp->next;
				delete temp;
				temp = temp2->next;
			}
			else {
				temp2 = temp;
				temp = temp->next;
			}
		}
	}
};


int main() {

	// TASK 1 
	LinkedList<int> list;
	//list.head = new Node(10);
	list.insertAtStart(2);
	list.insertAtStart(6);
	list.insertAtStart(7);
	list.insertAtEnd(9);
	list.print();
	cout << endl;
	list.insertAtStart(7);
	list.insertAtStart(8);
	list.insertAtStart(9);
	list.print();
	cout << endl;
	list.insertBefore(5, 9);
	list.print();
	cout << endl;
	cout << "2: " << list.search(2) << endl;
	cout << "9: " << list.search(9) << endl;
	cout << "10: " << list.search(10) << endl;
	cout << "5: " << list.search(5) << endl;
	list.DeleteAtStart();
	list.print();

	// =============== TASK 2 ======================

	list.insertAtStart(10);
	list.insertAtStart(9);
	list.insertAtStart(8);
	list.insertAtStart(7);
	list.insertAtStart(6);
	list.insertAtStart(5);
	list.deleteRange(6, 8);
	list.print();
}