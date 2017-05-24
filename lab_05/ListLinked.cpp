
#include "ListLinked.h"

// ListNode member functions

template <typename T>
List<T>::ListNode::ListNode(const T& nodeData, ListNode* nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename T>
List<T>::List(int ignored)
{
	cursor = nullptr;
	head = nullptr;
}

template <typename T>
List<T>::List(const List& other)
{
	*this = other;
}

template <typename T>
List<T>& List<T>::operator=(const List& other)
{
	cursor = other->cursor;
	head = other->head;
}

template <typename T>
List<T>::~List()
{
	clear();
	delete cursor;
	delete head;
}

template <typename T>
void List<T>::insert(const T& newDataItem) throw (logic_error)
{
	if (isFull()) throw logic_error("List is full");
	if (head->next == nullptr) {
		head = cursor = new ListNode(newDataItem, nullptr);
		return;
	}
	ListNode *node = new ListNode(newDataItem, cursor->next);
	cursor->next = node;
	cursor = node;
}

template <typename T>
void List<T>::remove() throw (logic_error)
{
	if (isEmpty()) throw logic_error("List is empty.");
    // FIXME: still need to relocate next if at the end.
    ListNode *next = cursor->next;
	delete cursor;
	cursor = next;
}

template <typename T>
void List<T>::replace(const T& newDataItem) throw (logic_error)
{
	if (isEmpty()) throw logic_error("List is empty.");
	cursor->dataItem = newDataItem;
}

template <typename T>
void List<T>::clear()
{
	while (cursor->next != nullptr) {
		remove();
	}
	head->next = nullptr;
}

template <typename T>
bool List<T>::isEmpty() const
{
	return cursor->next == nullptr && head->next == nullptr;
}

template <typename T>
bool List<T>::isFull() const
{
	return false;
}

template <typename T>
void List<T>::gotoBeginning() throw (logic_error)
{
	if (isEmpty()) throw logic_error("List is empty");
	cursor->next = head->next;
}

template <typename T>
void List<T>::gotoEnd() throw (logic_error)
{
}

template <typename T>
bool List<T>::gotoNext() throw (logic_error)
{
	return false;
}

template <typename T>
bool List<T>::gotoPrior() throw (logic_error)
{
	return false;
}

template <typename T>
T List<T>::getCursor() const throw (logic_error)
{
	T t;
	return t;
}

template <typename T>
void List<T>::moveToBeginning () throw (logic_error)
{
}

template <typename T>
void List<T>::insertBefore(const T& newDataItem) throw (logic_error)
{
}

#include "show5.cpp"

