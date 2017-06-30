// Author: Derek Sifford
#include "ExpressionTree.h"

template<typename T>
ExprTree<T>::ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr) {
	dataItem = elem;
	left = leftPtr;
	right = rightPtr;
}

template<typename T>
ExprTree<T>::ExprTree() {
	root = 0;
}

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
	if (from == 0) { return; }
	to = new ExprTreeNode(from->dataItem, 0, 0);
	copyHelper(to->left, from->left);
	copyHelper(to->right, from->right);
}

template<typename T>
ExprTree<T>::~ExprTree() {
	clearHelper(root);
}

template<typename T>
void ExprTree<T>::build() {
	string str;
	getline(cin, str);
	buildHelper(root, str);
}

template<typename T>
void ExprTree<T>::buildHelper(ExprTreeNode * &p, string &str) {
	if (str.empty()) { return; }
	if (str[0] == ' ') {
		return buildHelper(p, str.erase(0, 1));
	}
	p = new ExprTreeNode(str[0], 0, 0);
	if (is_same<T, bool>::value && (str[0] == '0' || str[0] == '1')) { return; }
	if (47 < static_cast<int>(str[0]) && static_cast<int>(str[0]) < 58) { return; }
	buildHelper(p->left, str.erase(0, 1));
	buildHelper(p->right, str.erase(0, 1));
}

template<typename T>
bool ExprTree<T>::isOperator(const ExprTreeNode *p) const {
	if (p == 0) return false;
	switch (p->dataItem) {
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}

template<typename T>
void ExprTree<T>::expression() const {
	exprHelper(root);
}

template<typename T>
void ExprTree<T>::exprHelper(ExprTreeNode *p) const {
	if (p == 0) return;
	if (!p->left && !p->right) {
		cout << p->dataItem;
		return;
	}
	if (is_same<T, bool>::value && p->dataItem == '-' && !p->right) {
		cout << "-" << p->left->dataItem;
		return;
	}
	if (!isOperator(p->left) || !isOperator(p->right)) {
		cout << "(";
	}
	exprHelper(p->left);
	if (isOperator(p)) {
		cout << " " << p->dataItem << " ";
	}
	else {
		cout << p->dataItem;
	}
	exprHelper(p->right);
	if (!isOperator(p->left) || !isOperator(p->right)) {
		cout << ")";
	}
}

template<typename T>
T ExprTree<T>::evaluate() const {
	if (!root) throw logic_error("Tree is empty");
	return evalHelper(root);
}

/**
 * NOTE 1: The GNU gcc compiler will not allow creating inline template specializations
 * in the way described in the lab book.
 *
 * NOTE 2: Why are we still using C++11 in 2017???????
 */
template<typename T>
T ExprTree<T>::evalHelper(ExprTreeNode *p) const {
	switch (p->dataItem) {
		case '+':
			return is_same<T, bool>::value
			? evalHelper(p->left) || evalHelper(p->right)
			: evalHelper(p->left) + evalHelper(p->right);
		case '-':
			return is_same<T, bool>::value
			? evalHelper(p->left) && ! evalHelper(p->right)
			: evalHelper(p->left) - evalHelper(p->right);
		case '*':
			return is_same<T, bool>::value
			? evalHelper(p->left) && evalHelper(p->right)
			: evalHelper(p->left) * evalHelper(p->right);
		case '/':
			if (is_same<T, bool>::value) {
				throw logic_error("Invalid operator for type bool");
			}
			return evalHelper(p->left) / evalHelper(p->right);
		default:
			return is_same<T, bool>::value
			? p->dataItem == '1'
			: static_cast<T>(p->dataItem) - 48;
	}
}

template<typename T>
void ExprTree<T>::clear() {
	clearHelper(root);
}

template<typename T>
void ExprTree<T>::clearHelper(ExprTreeNode * &p) {
	if (p == 0) return;
	clearHelper(p->left);
	clearHelper(p->right);
	p = 0;
}

template<typename T>
void ExprTree<T>::commute() {
	commuteHelper(root);
}

template<typename T>
void ExprTree<T>::commuteHelper(ExprTreeNode *p) {
	if (p == 0) return;
	ExprTreeNode *left = p->left;
	p->left = p->right;
	p->right = left;
	commuteHelper(p->left);
	commuteHelper(p->right);
}

template<typename T>
bool ExprTree<T>::isEquivalent(const ExprTree &source) const {
	return true;
}

template<typename T>
bool ExprTree<T>::isEquivalentHelper(const ExprTreeNode *x, const ExprTreeNode *y) const { return true; }

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
