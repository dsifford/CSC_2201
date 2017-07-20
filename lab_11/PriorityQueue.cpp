// Author (in part): Derek Sifford
// --------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1            PriorityQueue.cpp
//
//  ** SOLUTION: Heap implementation of the Priority Queue ADT **
//
// --------------------------------------------------------------------

#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP

using namespace std;

#include "PriorityQueue.h"

// Creates an empty priority queue.
template<typename T, typename KeyType, typename Comparator>
PriorityQueue<T, KeyType, Comparator>::PriorityQueue(int maxNumber): Heap<T>(maxNumber) {}

// Inserts newDataItem into a priority queue.
template<typename T, typename KeyType, typename Comparator>
void PriorityQueue<T, KeyType, Comparator>::enqueue(const T &newDataItem) {
	if (this->isFull()) throw logic_error("Queue is full");
	return this->insert(newDataItem);
}

// Removes the least recently added (front) data item from a priority
// queue and returns it.
template<typename T, typename KeyType, typename Comparator>
T PriorityQueue<T, KeyType, Comparator>::dequeue() {
	if (this->isEmpty()) throw logic_error("Queue is empty");
	return this->remove();
}

#endif
