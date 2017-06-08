// --------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
//
//  Class declaration for the linked implementation of the Stack ADT
//
// --------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>
using namespace std;

#include "Stack.h"

template<typename T>
class StackArray: public Stack<T> {
	public:
		StackArray(int maxNumber = Stack<T>::MAX_STACK_SIZE);
		StackArray(const StackArray &other);
		StackArray& operator=(const StackArray &other);

		~StackArray();

		void push(const T &newDataItem);
		T pop();

		void clear();

		bool isEmpty() const;
		bool isFull() const;

		void showStructure() const;

	private:
		int maxSize;
		int top;
		T *dataItems;
};

#endif          // #ifndef STACKARRAY_H
