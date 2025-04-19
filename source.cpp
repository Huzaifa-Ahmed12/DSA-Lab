#include<iostream>
using namespace std;
template<class ItemType>
class list {
protected:
	struct node {
		ItemType info;
		struct node* next;
	};
	typedef struct node* nodePtr;
	nodePtr listPtr;
public:
	list();
	~list();
	ItemType emptyList();
	void insertAfter(ItemType oldValue, ItemType newValue);
	ItemType deleteItem(ItemType oldValue);
	void push(ItemType newValue);
	ItemType pop();
	void display();
};
template<class ItemType>
list<ItemType>::list() {
	listPtr = 0;
}
template<class ItemType>
list<ItemType>::~list() {
	nodePtr p, q;
	if (emptyList()) {
		exit(0);
	}
	for (p = listPtr, q = p->next; p != 0; p = q, q = p->next);
	delete p;
}
template<class ItemType>
ItemType list<ItemType>::emptyList() {
	return listPtr == 0;
}
template<class ItemType>
void list<ItemType>::insertAfter(ItemType oldValue, ItemType newValue) {
	nodePtr p, q;
	for (p = listPtr; p != 0 && p->info != oldValue; p = p->next);
	if (p == 0) {
		cout << "Doesnot found!!";
		exit(0);
	}
	q = new node;
	q->info = newValue;
	q->next = p->next;
	p->next = q;
}
template<class ItemType>
ItemType list<ItemType>::deleteItem(ItemType oldValue) {
	nodePtr p, q;
	int x;
	for (q = 0, p = listPtr; p != 0 && p->info != oldValue; q = p, p = p->next);
	if (p == 0) {
		cout << "Not in list";
		exit(0);
	}
	else if (q == 0) {
		listPtr = p->next;
	}
	else {
		q->next = p->next;
	}
	x = p->info;
	delete p;
	return x;
}
template<class ItemType>
void list<ItemType>::push(ItemType newValue) {
	nodePtr p;
	p = new node;
	p->info = newValue;
	p->next = listPtr;
	listPtr = p;
}
template<class ItemType>
ItemType list<ItemType>::pop() {
	nodePtr p;
	ItemType x;
	p = listPtr;
	listPtr = p->next;
	x = p->info;
	delete p;
	return x;
}
template<class ItemType>
void list<ItemType>::display() {
	nodePtr p;
	p = listPtr;
	while (p != 0) {
		cout << p->info << "->";
		p = p->next;
	}
	cout <<"NULL";
}
int main() {
	list<int>l;
	l.push(7);
	l.insertAfter(7, 8);
	l.insertAfter(8, 9);
	l.insertAfter(9, 10);
	l.insertAfter(10, 11);
	l.deleteItem(8);
	l.pop();
	l.display();
	return 0;
}	