// Author: Derek Sifford
#include "Heap.h"

template<typename T, typename KeyType, typename Comparator>
Heap<T, KeyType, Comparator>::Heap(int maxNumber) {
	maxSize = maxNumber;
	size = 0;
	dataItems = new T[maxSize];
}

template<typename T, typename KeyType, typename Comparator>
Heap<T, KeyType, Comparator>::Heap(const Heap &other) {
	maxSize = other->maxNumber;
	size = 0;
	dataItems = new T[maxSize];
	for (auto &item : other->dataItems) {
		dataItems[size++] = item;
	}
}

template<typename T, typename KeyType, typename Comparator>
Heap<T, KeyType, Comparator>&Heap<T, KeyType, Comparator>::operator=(const Heap &other) {
	delete dataItems;
	maxSize = other->maxSize;
	size = 0;
	dataItems = new T[maxSize];
	for (auto &item : other->dataItems) {
		dataItems[size++] = item;
	}
	return *this;
}

template<typename T, typename KeyType, typename Comparator>
Heap<T, KeyType, Comparator>::~Heap() {
	delete [] dataItems;
}

template<typename T, typename KeyType, typename Comparator>
void Heap<T, KeyType, Comparator>::insert(const T &newDataItem) {
	if (isFull()) { throw logic_error("Heap is full"); }
	dataItems[size] = newDataItem;
	int currentIndex = size;
	int parentIndex = ((currentIndex + 1) / 2) - 1;
	T holder;
	while (comparator(dataItems[currentIndex].getPriority(), dataItems[parentIndex].getPriority()) && currentIndex != 0) {
		holder = dataItems[parentIndex];
		dataItems[parentIndex] = dataItems[currentIndex];
		dataItems[currentIndex] = holder;
		currentIndex = parentIndex;
		parentIndex = ((currentIndex + 1) / 2) - 1;
	}
	size++;
}

template<typename T, typename KeyType, typename Comparator>
T Heap<T, KeyType, Comparator>::remove() {
	if (isEmpty()) { throw logic_error("Heap is empty"); }
	T priority, parentItem, smallestChild;
	int parentIndex, leftChildIndex, rightChildIndex;

	priority = dataItems[0];
	dataItems[0] = parentItem = dataItems[--size];

	parentIndex = 0;
	leftChildIndex = ((parentIndex + 1) * 2) - 1;
	rightChildIndex = leftChildIndex + 1;

	while (
		comparator(dataItems[leftChildIndex].getPriority(), parentItem.getPriority()) ||
		comparator(dataItems[rightChildIndex].getPriority(), parentItem.getPriority())
	) {
		if (comparator(dataItems[leftChildIndex].getPriority(), dataItems[rightChildIndex].getPriority())) {
			smallestChild = dataItems[leftChildIndex];
			dataItems[leftChildIndex] = parentItem;
			dataItems[parentIndex] = smallestChild;
			parentIndex = leftChildIndex;
		}
		else {
			smallestChild = dataItems[rightChildIndex];
			dataItems[rightChildIndex] = parentItem;
			dataItems[parentIndex] = smallestChild;
			parentIndex = rightChildIndex;
		}
		leftChildIndex = ((parentIndex + 1) * 2) - 1;
		rightChildIndex = leftChildIndex + 1;
		if (leftChildIndex >= size || rightChildIndex >= size) { break; }
	}
	return priority;
}

template<typename T, typename KeyType, typename Comparator>
void Heap<T, KeyType, Comparator>::clear() {
	delete [] dataItems;
	dataItems = new T[maxSize];
	size = 0;
}

template<typename T, typename KeyType, typename Comparator>
bool Heap<T, KeyType, Comparator>::isEmpty() const {
	return size == 0;
}

template<typename T, typename KeyType, typename Comparator>
bool Heap<T, KeyType, Comparator>::isFull() const {
	return size == maxSize - 1;
}


template<typename T, typename KeyType, typename Comparator>
void Heap<T, KeyType, Comparator>::writeLevels() const {
	int levels, currentLevel, i;
	levels = size / 2;
	currentLevel = 1;
	i = 0;
	while (currentLevel <= levels) {
		int firstOfNextLevel = ((i + 1) * 2);
		while (i < firstOfNextLevel - 1) {
			cout << dataItems[i].getPriority() << " ";
			i++;
		}
		cout << endl;
		currentLevel++;
	}
}

#include "show11.cpp"
