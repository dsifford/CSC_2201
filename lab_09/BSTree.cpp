
#include "BSTree.h"

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyTreeHelper(BSTreeNode *&p, const BSTreeNode *otherPtr) {

}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clearHelper(BSTreeNode *p) {

}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insertHelper( BSTreeNode *&p, const DataType &newDataItem ) {

}

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )
{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ()
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )
{
	root = NULL;
	copyTreeHelper(root, other.root);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= ( const BSTree<DataType,KeyType>& other )
{
	clearHelper(root);
	copyTreeHelper(root, other.root);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree ()
{
	clearHelper(root);
	delete root;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )
{
	insertHelper(root, newDataItem);
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const
{
	return false;
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey )
{
	return false;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys () const
{
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear ()
{
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty () const
{
	return false;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight () const
{
	return -1;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount () const
{
	return -1;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ) const
{
}


#include "show9.cpp"
