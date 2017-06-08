#include "StackArray.h"

template<typename T>
StackArray<T>::StackArray(int maxNumber) {
	maxSize = maxNumber;
	dataItems = new T;
	top = -1;
}

template<typename T>
StackArray<T>::StackArray(const StackArray &other) {
	maxSize = other.maxNumber;
	dataItems = new T;
	top = -1;
	while (top != other.top) {
		push(other.dataItems[top]);
	}
}

template<typename T>
StackArray<T>&StackArray<T>::operator=(const StackArray &other) {
	while (top > other.top) {
		pop();
	}
	top = -1;
	while (top != other.top) {
		push(other.dataItems[top]);
	}
}

template<typename T>
StackArray<T>::~StackArray() {
	clear();
	delete [] dataItems;
}

template<typename T>
void StackArray<T>::push(const T &newDataItem) {
	if (isFull()) {
		throw logic_error("Stack is already full");
	}
	top++;
	dataItems[top] = newDataItem;
}

template<typename T>
T StackArray<T>::pop() {
	if (isEmpty()) {
		throw logic_error("Stack is empty");
	}
	return dataItems[top--];
}

template<typename T>
void StackArray<T>::clear() {
	while (!isEmpty()) {
		pop();
	}
}

template<typename T>
bool StackArray<T>::isEmpty() const {
	return top == -1;
}

template<typename T>
bool StackArray<T>::isFull() const {
	return top == maxSize - 1;
}

template<typename T>
void StackArray<T>::showStructure() const
// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.
{
	if (isEmpty()) {
		cout << "Empty stack." << endl;
	}
	else {
		int j;
		cout << "Top = " << top << endl;
		for (j = 0; j < maxSize; j++) {
			cout << j << "\t";
		}
		cout << endl;
		for (j = 0; j <= top; j++) {
			if (j == top) {
				cout << '[' << dataItems[j] << ']' << "\t"; // Identify top
			}
			else {
				cout << dataItems[j] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}
