#include<iostream>
using namespace std;

template<typename T> class LinkedList
{
private:
    
    struct Node
    {
    public:
        T data;
        Node* next;
        Node() {
            next= NULL;
        }
        Node(T data, Node* ptr=0) {
            this->data=data;
            next=ptr;
        }
    };
    
public:

    Node* head;
    LinkedList() {
        next = NULL;
    }

    ~LinkedList(){
        Node* temp = head;
        while(temp->next) {
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

    void merge(LinkedList<T>& other) {

        if (head == NULL) {
            head = other.head;
            other.head = NULL;
            return;
        }

        Node* temtemp1 = head;
        Node* temp2 = other.head;

        if (temp2->data < temp1->data) {
            head = temp2;
            temp2 = temp2->next;
        }
        else {
            temp1 = temp1->next;
        }

        Node* current = head;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data <= temp2->data) {
                current->next = temp1;
                temp1 = temp1->next;
            }
            else {
                current->next = temp2;
                temp2 = temp2->next;
            }
            current = current->next;
        }

        if (temp1 != NULL) {
            current->next = temp1;
        }
        if (temp2 != NULL) {
            current->next = temp2;
        }

        other.head = NULL;
    }
};



int main(){
    LinkedList<int> list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);
    list1.insertAtEnd(7);

    LinkedList<int> list2;
    list2.insertAtStart(2);
    list2.insertAtStart(4);
    list2.insertAtStart(6);
    list2.insertAtStart(8);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    list1.merge(list2);

    cout << "Merged sorted list: ";
    list1.print();

}