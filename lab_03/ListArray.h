//--------------------------------------------------------------------
//
//  Laboratory 3                                           ListArray.h
//  **Instructor's Solution**
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class List {
	public:
		static const int MAX_LIST_SIZE = 10; // Default maximum list size

		// Constructors
		List(int maxNumber = MAX_LIST_SIZE); // Default constructor
		List(const List &source);    // Copy constructor

		// Overloaded assignment operator
		List &operator=(const List &source);

		// Destructor
		virtual ~List();

		// List manipulation operations
		virtual void insert(const T &newDataItem) throw(logic_error);
		void remove() throw(logic_error);
		virtual void replace(const T &newDataItem) throw(logic_error);
		void clear();

		// List status operations
		bool isEmpty() const; // List is empty
		bool isFull() const; // List is full

		// List iteration operations
		void gotoBeginning() throw(logic_error);
		void gotoEnd() throw(logic_error);
		bool gotoNext() throw(logic_error);
		bool gotoPrior() throw(logic_error);
		T getCursor() const throw(logic_error);

		// Output the list structure -- used in testing/debugging
		virtual void showStructure() const;

		// In-lab operations
		void moveToNth(int n) throw(logic_error);
		bool find(const T &searchDataItem) throw(logic_error);

	protected:
		int maxSize;  // Maximum size of array
		int size;     // Actual number of data item in the list
		int cursor;   // Cursor array index
		T *dataItems; // Array containing the list data item
};

#endif
