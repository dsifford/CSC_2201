// Author: Derek Sifford
#include "QueueLinked.h"

template<typename T>
QueueLinked<T>::QueueNode::QueueNode(const T &nodeData, QueueNode *nextPtr) {
	dataItem = nodeData;
	next = nextPtr;
}

template<typename T>
QueueLinked<T>::QueueLinked(int maxNumber) {
	(void) maxNumber;
	front = 0;
	back = 0;
}

template<typename T>
QueueLinked<T>::QueueLinked(const QueueLinked &other) {
	QueueNode *iter = new QueueNode(other.front->dataItem, other.front->next);

	while (iter) {
		QueueNode *node = new QueueNode(iter->dataItem, iter->next);
		if (!front) {
			front = back = node;
		}
		else {
			back->next = node;
			back = node;
		}
		iter = iter->next;
	}
}

template<typename T>
QueueLinked<T>&QueueLinked<T>::operator=(const QueueLinked &other) {
	clear();

	QueueNode *iter = other.front;

	while (iter) {
		QueueNode *node = new QueueNode(iter->dataItem, iter->next);
		if (!front) {
			front = back = node;
		}
		else {
			back->next = node;
			back = node;
		}
		iter = iter->next;
	}
}

template<typename T>
QueueLinked<T>::~QueueLinked() {
	clear();
}

template<typename T>
void QueueLinked<T>::enqueue(const T &newDataItem) {
	QueueNode *node = new QueueNode(newDataItem, 0);
	if (isEmpty()) {
		front = back = node;
	}
	else {
		back->next = node;
		back = node;
	}
}

template<typename T>
T QueueLinked<T>::dequeue() {
	if (isEmpty()) {
		throw logic_error("Queue is already empty");
	}
	QueueNode *node = front->next;
	T data = front->dataItem;
	delete front;
	front = node;
	return data;
}

template<typename T>
void QueueLinked<T>::clear() {
	QueueNode *node;
	while (front) {
		node = front;
		front = front->next;
		delete node;
	}
}

template<typename T>
bool QueueLinked<T>::isEmpty() const {
	return front == 0;
}

template<typename T>
bool QueueLinked<T>::isFull() const {
	return false;
}

template<typename T>
void QueueLinked<T>::putFront(const T &newDataItem) {
	if (isEmpty()) {
		enqueue(newDataItem);
		return;
	}
	QueueNode *node = new QueueNode(newDataItem, front);
	front = node;
}

template<typename T>
T QueueLinked<T>::getRear() {
	if (isEmpty()) {
		throw logic_error("Queue is already empty");
	}
	T data = back->dataItem;
	QueueNode *node = front;
	while (node->next != back) {
		node = node->next;
	}
	back = node;
	back->next = 0;
	return data;
}

template<typename T>
int QueueLinked<T>::getLength() const {
	int len = 0;
	QueueNode *node = front;
	while (node) {
		len++;
		node = node->next;
	}
	return len;
}

template<typename T>
void QueueLinked<T>::showStructure() const {
	QueueNode *p;   // Iterates through the queue

	if (isEmpty()) {
		cout << "Empty queue" << endl;
	}
	else {
		cout << "Front\t";
		for (p = front; p != 0; p = p->next) {
			if (p == front) {
				cout << '[' << p->dataItem << "] ";
			}
			else {
				cout << p->dataItem << " ";
			}
		}
		cout << "\trear" << endl;
	}
}
