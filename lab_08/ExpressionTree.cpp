// Author: Derek Sifford
#include "ExpressionTree.h"

template<typename T>
ExprTree<T>::ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr) {
	dataItem = elem;
	left = leftPtr;
	right = rightPtr;
}

template<typename T>
ExprTree<T>::ExprTree() {}

template<typename T>
ExprTree<T>::ExprTree(const ExprTree &source) {
	copyHelper(root, source.root);
}

template<typename T>
ExprTree<T>&ExprTree<T>::operator=(const ExprTree &source) {
	clearHelper(root);
	copyHelper(root, source->root);
}

template<typename T>
void ExprTree<T>::copyHelper(ExprTreeNode* &to, const ExprTreeNode *from) {
	if (from == 0) return;
	to = new ExprTreeNode(from->dataItem, 0, 0);
	copyHelper(to->left, from->left);
	copyHelper(to->right, from->right);
}

template<typename T>
ExprTree<T>::~ExprTree() {
	clearHelper(root);
}

template<typename T>
void ExprTree<T>::build() {}

template<>
void ExprTree<float>::buildHelper(ExprTreeNode* &p) {}

template<>
void ExprTree<bool>::buildHelper(ExprTreeNode* &p) {}

template<typename T>
void ExprTree<T>::expression() const {}

template<typename T>
void ExprTree<T>::exprHelper(ExprTreeNode *p) const {}

template<typename T>
T ExprTree<T>::evaluate() const throw(logic_error) {
	T temp;
	return temp;
}

template<>
float ExprTree<float>::evalHelper(ExprTreeNode *p) const {
	float temp;
	return temp;
}

template<>
bool ExprTree<bool>::evalHelper(ExprTreeNode *p) const {
	bool temp;
	return temp;
}

template<typename T>
void ExprTree<T>::clear() {}

template<typename T>
void ExprTree<T>::clearHelper(ExprTreeNode *&p) {}

template<typename T>
void ExprTree<T>::commute() {}

template<typename T>
void ExprTree<T>::commuteHelper(ExprTreeNode *p) {}

template<typename T>
bool ExprTree<T>::isEquivalent(const ExprTree &source) const {}

template<typename T>
bool ExprTree<T>::isEquivalentHelper(
	const ExprTreeNode *x,
	const ExprTreeNode *y
) const {}

template<typename T>
bool ExprTree<T>::isEmpty() const {
	return false;
}

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.
template<typename T>
void ExprTree<T>::showStructure() const {
	// No isEmpty function in this class. Add a private one if you wish.
	if (root == 0) {
		cout << "Empty tree" << endl;
	}
	else {
		cout << endl;
		showHelper(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Recursive helper for the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.
template<typename T>
void ExprTree<T>::showHelper(ExprTreeNode *p, int level) const {
	int j;   // Loop counter

	if (p != 0) {
		showHelper(p->right, level + 1);        // Output right subtree
		for (j = 0; j < level; j++) { // Tab over to level
			cout << "\t";
		}
		cout << " " << p->dataItem;        // Output dataItem
		if ((p->left != 0) &&          // Output "connector"
		    (p->right != 0)) {
			cout << "<";
		}
		else if (p->right != 0) {
			cout << "/";
		}
		else if (p->left != 0) {
			cout << "\\";
		}
		cout << endl;
		showHelper(p->left, level + 1);         // Output left subtree
	}
}
