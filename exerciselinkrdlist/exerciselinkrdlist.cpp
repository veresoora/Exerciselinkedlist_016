#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** kusuma, Node** nadia);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //untuk menambahkan newnode kedalam circularlinkedlist, memasukkan rollnumber dan nama newnode akan ditambahkan 
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of student : ";
	cin.ignore();
	getline(cin, nm);
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = nm;

	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "Buat Linked List terlebih dahulu" << endl;
			return;
		}

		LAST = newNode;
		newNode->next = LAST;
		return;
	}

	Node* nadia = LAST;
	Node* kusuma = NULL;
	
}

bool CircularLinkedList::search(int rollno, Node** kusuma, Node** nadia) { //mencari apakah ada node dengan nomor rollnumber tertentu, mengembalikan 2 pointer yaitu pointer nadia dan kusuma
	*kusuma = LAST->next;
	*nadia = LAST->next;
	while (*nadia != LAST) {
		if (rollno == (*nadia)->rollNumber) {
			return true;
		}
		*kusuma = *nadia;
		*nadia = (*nadia)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() { //untuk mengembalikan nilai true jika circularLinkedList kosong, false jika berisi node
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //untuk menghapus node dari circularLinkedList mengikuti rollNumber yang telah dimasukkan user
	if (listEmpty()) {
		cout << "List is empty" << endl;
		return false;
	}

	if (LAST->next == LAST) {
		Node* nadia = LAST->next;
		LAST->next = nadia->next;
		delete nadia;
	}

}

void CircularLinkedList::traverse() { //untuk menampilkan semua node dalam circularLinkedList
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}