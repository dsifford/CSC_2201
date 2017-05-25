#include "ListLinked.h"
using namespace std;

// ListNode member functions

template<typename T>
List<T>::ListNode::ListNode(const T &nodeData, ListNode *nextPtr) {
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template<typename T>
List<T>::List(int ignored) {
	(void)ignored;
	cursor = 0;
	head = 0;
}

template<typename T>
List<T>::List(const List &other) {
	*this = other;
}

template<typename T>
List<T>&List<T>::operator=(const List &other) {
	cursor = other->cursor;
	head = other->head;
}

template<typename T>
List<T>::~List() {
	clear();
	delete cursor;
	delete head;
}

template<typename T>
void List<T>::insert(const T &newDataItem) throw(logic_error) {
	if (isFull()) {
		throw logic_error("List is full");
	}
	if (head == 0) {
		head = cursor = new ListNode(newDataItem, 0);
		return;
	}
	ListNode *node = new ListNode(newDataItem, cursor->next);
	cursor->next = node;
	cursor = node;
}

template<typename T>
void List<T>::remove() throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty.");
	}

	ListNode *next;

	// Cursor is at first index
	if (cursor == head) {
		next = head = cursor->next == 0 ? 0 : cursor->next;
	}
	// Cursor is in the middle somewhere
	else if (cursor->next != 0) {
		ListNode *prev = head;
		while (prev->next != cursor) {
			prev = prev->next;
		}
		prev->next = cursor->next;
		next = cursor->next;
	}
	// Cursor is at last index
	else {
		next = head;
		while (next->next != cursor) {
			next = next->next;
		}
		next->next = 0;
		next = head;
	}

	delete cursor;
	cursor = next;
}

template<typename T>
void List<T>::replace(const T &newDataItem) throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty.");
	}
	cursor->dataItem = newDataItem;
}

template<typename T>
void List<T>::clear() {
	while (!isEmpty()) {
		remove();
	}
}

template<typename T>
bool List<T>::isEmpty() const {
	return cursor == 0 && head == 0;
}

template<typename T>
bool List<T>::isFull() const {
	return false;
}

template<typename T>
void List<T>::gotoBeginning() throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	cursor = head;
}

template<typename T>
void List<T>::gotoEnd() throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	while (cursor->next != 0) {
		cursor = cursor->next;
	}
}

template<typename T>
bool List<T>::gotoNext() throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	if (cursor->next == 0) {
		return false;
	}
	cursor = cursor->next;
	return true;
}

template<typename T>
bool List<T>::gotoPrior() throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	if (cursor == head) {
		return false;
	}
	ListNode *node = head;
	while (node->next != cursor) {
		node = node->next;
	}
	cursor = node;
	return true;
}

template<typename T>
T List<T>::getCursor() const throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	T t = cursor->dataItem;
	return t;
}

template<typename T>
void List<T>::moveToBeginning() throw(logic_error) {
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	if (cursor == head) {
		return;
	}
	ListNode *node = head;
	while (node->next != cursor) {
		node = node->next;
	}
	node->next = cursor->next;
	cursor->next = head;
	head = cursor;
}

template<typename T>
void List<T>::insertBefore(const T &newDataItem) throw(logic_error) {
	if (isEmpty()) {
		insert(newDataItem);
		return;
	}
	ListNode *cursorCopy = cursor;
	insert(cursor->dataItem);
    cursor = cursorCopy;
	cursor->dataItem = newDataItem;
}

#include "show5.cpp"
