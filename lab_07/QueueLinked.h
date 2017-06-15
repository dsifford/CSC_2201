// QueueLinked.h

#include <stdexcept>
#include <iostream>
using namespace std;

#include "Queue.h"

template<typename T>
class QueueLinked: public Queue<T> {
	public:
		QueueLinked(int maxNumber = Queue<T>::MAX_QUEUE_SIZE);
		QueueLinked(const QueueLinked &other);
		QueueLinked& operator=(const QueueLinked &other);

		~QueueLinked();

		void enqueue(const T &newDataItem);
		T dequeue();

		void clear();

		bool isEmpty() const;
		bool isFull() const;

		// Programming Exercise 2
		void putFront(const T &newDataItem);
		T getRear();

		// Programming Exercise 3
		int getLength() const;

		void showStructure() const;

	private:
		class QueueNode {
			public:
				QueueNode(const T &nodeData, QueueNode *nextPtr);

				T dataItem;
				QueueNode *next;
		};

		QueueNode *front;
		QueueNode *back;
};
