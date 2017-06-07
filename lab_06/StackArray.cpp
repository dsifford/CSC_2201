
#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{

}

template <typename DataType>
void StackArray<DataType>::clear()
{
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}