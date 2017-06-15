// Author: Derek Sifford
#include "QueueArray.h"

template<typename T>
QueueArray<T>::QueueArray(int maxNumber) {
	maxSize = maxNumber;
	front = back = -1;
	dataItems = new T[maxSize];
}

template<typename T>
QueueArray<T>::QueueArray(const QueueArray &other) {
	int position;
	maxSize = other.maxSize;
	front = back = position = other.front;
	dataItems = new T[maxSize];
	while (position != other.back) {
		dataItems[back] = other[position];
		position = position == (maxSize - 1) ? 0 : position + 1;
	}
}

template<typename T>
QueueArray<T>&QueueArray<T>::operator=(const QueueArray &other) {
	int position;
	clear();
	delete [] dataItems;

	maxSize = other.maxSize;
	front = back = position = other.front;
	dataItems = new T[maxSize];
	while (position != other.back) {
		dataItems[back] = other[position];
		position = position == (maxSize - 1) ? 0 : position + 1;
	}
	return *this;
}

template<typename T>
QueueArray<T>::~QueueArray() {
	clear();
	delete [] dataItems;
}

template<typename T>
void QueueArray<T>::enqueue(const T &newDataItem) {
	if (isFull()) {
		throw logic_error("Queue is full");
	}
	if (front == -1) {
		front++;
	}
	back = back == (maxSize - 1) ? 0 : back + 1;
	dataItems[back] = newDataItem;
}

template<typename T>
T QueueArray<T>::dequeue() {
	if (isEmpty()) {
		throw logic_error("Queue is empty");
	}
	T frontItem = dataItems[front];
	if (back == front) {
		dataItems[back] = 0;
		dataItems[front] = 0;
		back = front = -1;
	}
	else {
		front = front == (maxSize - 1) ? 0 : front + 1;
	}
	return frontItem;
}

template<typename T>
void QueueArray<T>::clear() {
	for (int i = 0; i < maxSize; i++) {
		dataItems[i] = 0;
	}
	back = front = -1;
}

template<typename T>
bool QueueArray<T>::isEmpty() const {
	return back == front && dataItems[front] == 0;
}

template<typename T>
bool QueueArray<T>::isFull() const {
	return back < front ?
	       back == front - 1 : back == (maxSize - 1) && front == 0;
}

template<typename T>
void QueueArray<T>::putFront(const T &newDataItem) {
	if (isFull()) {
		throw logic_error("Queue is already full");
	}
	front = front == 0 ? (maxSize - 1) : front - 1;
	dataItems[front] = newDataItem;
}

template<typename T>
T QueueArray<T>::getRear() {
	if (isEmpty()) {
		throw logic_error("Queue is already empty");
	}
	T rearItem = dataItems[back];
	back = back == 0 ? (maxSize - 1) : back - 1;
	return rearItem;
}

template<typename T>
int QueueArray<T>::getLength() const {
	if (isEmpty()) {
		return 0;
	}
	if (isFull()) {
		return maxSize;
	}
	int len = 1;
	int cursor = front;
	while (cursor != back) {
		len++;
		cursor = cursor == (maxSize - 1) ? 0 : cursor + 1;
	}
	return len;
}

// --------------------------------------------------------------------

template<typename T>
void QueueArray<T>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.
{
	int j;   // Loop counter

	if (front == -1) {
		cout << "Empty queue" << endl;
	}
	else {
		cout << "Front = " << front << "  Back = " << back << endl;
		for (j = 0; j < maxSize; j++) {
			cout << j << "\t";
		}
		cout << endl;
		if (back >= front) {
			for (j = 0; j < maxSize; j++) {
				if ((j >= front) && (j <= back)) {
					cout << dataItems[j] << "\t";
				}
				else {
					cout << " \t";
				}
			}
		}
		else {
			for (j = 0; j < maxSize; j++) {
				if ((j >= front) || (j <= back)) {
					cout << dataItems[j] << "\t";
				}
				else {
					cout << " \t";
				}
			}
		}
		cout << endl;
	}
}
