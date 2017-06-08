#include "StackLinked.h"

template<typename T>
StackLinked<T>::StackLinked(int maxNumber) {
	maxSize = maxNumber;
	top = 0;
	size = 0;
}

template<typename T>
StackLinked<T>::StackLinked(const StackLinked &other) {
	size = 0;
	StackNode *iter;
	int i;
	while (size != other.size) {
		iter = other.top;
		i = other.size;
		while (i > size - 1) {
			iter = iter->next;
		}
		StackNode *newNode = new StackNode(iter->dataItem, iter->next);
		top = newNode;
		size++;
	}
}

template<typename T>
StackLinked<T>&StackLinked<T>::operator=(const StackLinked &other) {
	while (size > other.size) {
		pop();
	}
	size = 0;
	StackNode *iter;
	int i;
	while (size != other.size) {
		iter = other.top;
		i = other.size;
		while (i > size - 1) {
			iter = iter->next;
		}
		StackNode *newNode = new StackNode(iter->dataItem, iter->next);
		top = newNode;
		size++;
	}
}

template<typename T>
StackLinked<T>::~StackLinked() {
	clear();
	delete top;
}

template<typename T>
void StackLinked<T>::push(const T &newDataItem) {
	if (isFull()) {
		throw logic_error("Stack is already full");
	}
	size++;
	if (isEmpty()) {
		top = new StackNode(newDataItem, 0);
		return;
	}
	StackNode *newNode = new StackNode(newDataItem, top);
	top = newNode;
}

template<typename T>
T StackLinked<T>::pop() {
	if (isEmpty()) {
		throw logic_error("Stack is already empty");
	}
	size--;
	T item = top->dataItem;
	StackNode *popped = top;
	top = top->next;
	delete popped;
	return item;
}

template<typename T>
void StackLinked<T>::clear() {
	while (!isEmpty()) {
		pop();
	}
}

template<typename T>
bool StackLinked<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
bool StackLinked<T>::isFull() const {
	return size == maxSize;
}

template<typename T>
void StackLinked<T>::showStructure() const {
	if (isEmpty()) {
		cout << "Empty stack" << endl;
	}
	else {
		cout << "Top\t";
		for (StackNode *temp = top; temp != 0; temp = temp->next) {
			if (temp == top) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}
}
