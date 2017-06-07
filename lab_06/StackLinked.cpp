
#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber)
{
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode* t;
	while ( top != NULL)
	{
		t = top;
		top = top->next;
		delete t;
	}
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    return false;
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}