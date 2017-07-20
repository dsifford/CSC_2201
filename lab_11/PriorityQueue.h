// --------------------------------------------------------------------
//
//  Laboratory 12, Programming Exercise 1              PriorityQueue.h
//
//  Class declaration for the heap implementation of the
//  Priority Queue ADT -- inherits the array implementation of the
//  Heap ADT
//
// --------------------------------------------------------------------

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdexcept>
#include <iostream>
using namespace std;

#include "Heap.cpp"

const int defMaxQueueSize = 10;   // Default maximum queue size

template<typename T, typename KeyType = int, typename Comparator = Less<KeyType> >
class PriorityQueue: public Heap<T> {
	public:

		// Constructor
		PriorityQueue(int maxNumber = defMaxQueueSize);

		// Queue manipulation operations
		void enqueue(const T &newDataItem);   // Enqueue data element
		T dequeue();                            // Dequeue data element
};

#endif
