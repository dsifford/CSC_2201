// --------------------------------------------------------------------
//
//  Laboratory 6                                          StackArray.h
//
//  Class declaration for the array implementation of the Stack ADT
//
// --------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>
using namespace std;

#include "Stack.h"

template<typename T>
class StackLinked: public Stack<T> {

    public:

        StackLinked(int maxNumber = Stack<T>::MAX_STACK_SIZE);
        StackLinked(const StackLinked &other);
        StackLinked& operator=(const StackLinked &other);

        ~StackLinked();

        void push(const T &newDataItem);
        T pop();

        void clear();

        bool isEmpty() const;
        bool isFull() const;

        void showStructure() const;

    private:

        class StackNode {
            public:
                StackNode(const T &nodeData, StackNode *nextPtr) {
                    dataItem = nodeData;
                    next = nextPtr;
                }

                T dataItem;
                StackNode *next;
        };
		int maxSize;
		int size;
        StackNode *top;
};

#endif          // #ifndef STACKARRAY_H
