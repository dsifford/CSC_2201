
#include "HashTable.h"

template <typename T, typename KeyType>
HashTable<T, KeyType>::HashTable(int initTableSize) {
	tableSize = initTableSize;
	dataTable = new BSTree<T, KeyType>[tableSize];
}

template <typename T, typename KeyType>
HashTable<T, KeyType>::HashTable(const HashTable &other)
{
	tableSize = other.tableSize;
	dataTable = new BSTree<T, KeyType>[tableSize];
	copyTable(other);
}

template <typename T, typename KeyType>
HashTable<T, KeyType> &HashTable<T, KeyType>::operator=(const HashTable &other)
{
	clear();
	copyTable(other);
}

template <typename T, typename KeyType>
HashTable<T, KeyType>::~HashTable()
{
	clear();
}

template <typename T, typename KeyType>
void HashTable<T, KeyType>::insert(const T &newDataItem)
{
	uint loc = T::hash(newDataItem.getKey()) % tableSize;
	dataTable[loc].insert(newDataItem);
}

template <typename T, typename KeyType>
bool HashTable<T, KeyType>::remove(const KeyType &deleteKey)
{
	return false;
}

template <typename T, typename KeyType>
bool HashTable<T, KeyType>::retrieve(const KeyType &searchKey, T &returnItem) const
{
	return false;
}

template <typename T, typename KeyType>
void HashTable<T, KeyType>::clear()
{
}

template <typename T, typename KeyType>
bool HashTable<T, KeyType>::isEmpty() const
{
	return true;
}

#include "show10.cpp"

template <typename T, typename KeyType>
double HashTable<T, KeyType>::standardDeviation() const
{
}

template <typename T, typename KeyType>
void HashTable<T, KeyType>::copyTable(const HashTable &source)
{
}
