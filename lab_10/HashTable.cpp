#include "HashTable.h"

template<typename T, typename KeyType>
HashTable<T, KeyType>::HashTable(int initTableSize) {
	tableSize = initTableSize;
	dataTable = new BSTree<T, KeyType>[tableSize];
}

template<typename T, typename KeyType>
HashTable<T, KeyType>::HashTable(const HashTable &other) {
	tableSize = other.tableSize;
	dataTable = new BSTree<T, KeyType>[tableSize];
	copyTable(other);
}

template<typename T, typename KeyType>
HashTable<T, KeyType>&HashTable<T, KeyType>::operator=(const HashTable &other) {
	clear();
	copyTable(other);
}

template<typename T, typename KeyType>
HashTable<T, KeyType>::~HashTable() {
	clear();
}

template<typename T, typename KeyType>
void HashTable<T, KeyType>::insert(const T &newDataItem) {
	uint loc = T::hash(newDataItem.getKey()) % tableSize;
	dataTable[loc].insert(newDataItem);
}

template<typename T, typename KeyType>
bool HashTable<T, KeyType>::remove(const KeyType &deleteKey) {
	uint loc = T::hash(deleteKey) % tableSize;
	return dataTable[loc].remove(deleteKey);
}

template<typename T, typename KeyType>
bool HashTable<T, KeyType>::retrieve(const KeyType &searchKey, T &returnItem) const {
	uint loc = T::hash(searchKey) % tableSize;
	return dataTable[loc].retrieve(searchKey, returnItem);
}

template<typename T, typename KeyType>
void HashTable<T, KeyType>::clear() {
	for (int i = 0; i < tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			dataTable[i].clear();
		}
	}
}

template<typename T, typename KeyType>
bool HashTable<T, KeyType>::isEmpty() const {
	for (int i = 0; i < tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			return false;
		}
	}
	return true;
}

#include "show10.cpp"

template<typename T, typename KeyType>
double HashTable<T, KeyType>::standardDeviation() const {
	double xbar, sumOfSquares;
	int i, n = 0, totalNodes = 0;

	for (i = 0; i < tableSize; i++) {
		if (dataTable[i].isEmpty()) { continue; }
		totalNodes += dataTable[i].getCount();
		n++;
	}

	xbar = totalNodes / n;

	for (i = 0; i < tableSize; i++) {
		if (dataTable[i].isEmpty()) { continue; }
		sumOfSquares += pow((dataTable[i].getCount() - xbar), 2);
	}

	return (n - 1) == 0 ? 0 : sqrt(sumOfSquares / (n - 1));
}

template<typename T, typename KeyType>
void HashTable<T, KeyType>::copyTable(const HashTable &source) {}
