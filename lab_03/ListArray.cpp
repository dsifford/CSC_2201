
#include "ListArray.h"

template <typename T>
List<T>::List(int maxNumber)
{
    maxSize = maxNumber;
    cursor = -1;
    size = 0;
    dataItems = new T[maxNumber];
}

template <typename T>
List<T>::List(const List &source)
{
    maxSize = source.maxSize;
    cursor = source.cursor;
    size = source.size;
    delete [] dataItems;
    dataItems = new T[maxSize];
    for (int i = 0; i < source.maxSize; i++) {
        dataItems[i] = source.dataItems[i];
    }
}

template <typename T>
List<T> &List<T>::operator=(const List &source)
{
    maxSize = source.maxSize;
    cursor = source.cursor;
    size = source.size;
    delete [] dataItems;
    dataItems = new T[maxSize];
    for (int i = 0; i < source.maxSize; i++) {
        dataItems[i] = source.dataItems[i];
    }
    return *this;
}

template <typename T>
List<T>::~List()
{
    delete [] dataItems;
}

template <typename T>
void List<T>::insert(const T &newDataItem) throw(logic_error)
{
    size++;
    dataItems[++cursor] = newDataItem;
}

template <typename T>
void List<T>::remove() throw(logic_error)
{
    if (size == 0) return;
    dataItems[cursor] = NULL;
    size--;
    cursor--;
}

template <typename T>
void List<T>::replace(const T &newDataItem) throw(logic_error)
{
    if (cursor == -1) {
        throw logic_error("Array is empty. Nothing to replace.");
    }
    dataItems[cursor] = newDataItem;
}

template <typename T>
void List<T>::clear()
{
    for (int i = size - 1; i >= 0; i--) {
        dataItems[i] = NULL;
    }
    size = 0;
}

template <typename T>
bool List<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
bool List<T>::isFull() const
{
    return size == maxSize;
}

template <typename T>
void List<T>::gotoBeginning() throw(logic_error)
{
    if (cursor < 1) return;
    cursor = 0;
}

template <typename T>
void List<T>::gotoEnd() throw(logic_error)
{
    cursor = size - 1;
}

template <typename T>
bool List<T>::gotoNext() throw(logic_error)
{
    if (cursor == size - 1)
        return false;
    cursor++;
    return true;
}

template <typename T>
bool List<T>::gotoPrior() throw(logic_error)
{
    if (cursor < 1)
        return false;
    cursor--;
    return true;
}

template <typename T>
T List<T>::getCursor() const
    throw(logic_error)
{
    T t = dataItems[cursor];
    return t;
}

#include "show3.cpp"

template <typename T>
void List<T>::moveToNth(int n) throw(logic_error)
{
    if (n > size - 1 || n < 0) throw logic_error("n is out of bounds.");
    cursor = n;
}

template <typename T>
bool List<T>::find(const T &searchDataItem) throw(logic_error)
{
    cursor = 0;
    for (int i = 0; i < size - 1; i++) {
        if (dataItems[i] == searchDataItem) return true;
        cursor++;
    }
    return false;
}