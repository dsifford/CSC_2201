
#include "QueueArray.h"

template <typename T>
QueueArray<T>::QueueArray(int maxNumber)
{
	maxSize = maxNumber;
	front = back = 0;
	dataItems = new T[maxSize];
}

template <typename T>
QueueArray<T>::QueueArray(const QueueArray& other)
{
	maxSize = other.maxSize;
	front = 0;
	back = 0;
	dataItems = new T;
	int position = other.front;
	while (position != other.back) {
		dataItems[back] = other[position];
		position = position == (maxSize - 1) ? 0 : position + 1;
	}
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(const QueueArray& other)
{
	clear();
	maxSize = other.maxSize;
	front = 0;
	back = 0;
	dataItems = new T;
	int position = other.front;
	while (position != other.back) {
		dataItems[back] = other[position];
		position = position == (maxSize - 1) ? 0 : position + 1;
	}
	return *this;
}

template <typename T>
QueueArray<T>::~QueueArray()
{
	clear();
	delete [] dataItems;
}


template <typename T>
void QueueArray<T>::enqueue(const T& newDataItem) throw (logic_error)
{
	if (isFull()) {
		throw logic_error("Queue is full");
	}
	dataItems[back] = newDataItem;
	back = back == (maxSize - 1) ? 0 : back + 1;
}

template <typename T>
T QueueArray<T>::dequeue() throw (logic_error)
{
	if (isEmpty()) {
		throw logic_error("Queue is empty");
	}
    T temp = dataItems[front];
	dataItems[front] = 0;
	if (front == maxSize - 1) {
		front = 0;
	}
	else {
		front++;
	}
    return temp;
}

template <typename T>
void QueueArray<T>::clear()
{
	while (back != front) {
		dataItems[back] = 0;
		back = back == 0 ? maxSize - 1 : back - 1;
	}
}

template <typename T>
bool QueueArray<T>::isEmpty() const
{
    return back == front && dataItems[front] == 0;
}

template <typename T>
bool QueueArray<T>::isFull() const
{
    return back == front && dataItems[front] != 0;
}

template <typename T>
void QueueArray<T>::putFront(const T& newDataItem) throw (logic_error)
{
}

template <typename T>
T QueueArray<T>::getRear() throw (logic_error)
{
    T temp;
    return temp;
}

template <typename T>
int QueueArray<T>::getLength() const
{
    return -1;
}

//--------------------------------------------------------------------

template <typename T>
void QueueArray<T>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}