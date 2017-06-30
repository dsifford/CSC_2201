// --------------------------------------------------------------------
//
//  Laboratory 8                                     ExpressionTree.h
//
//  Class declarations for the linked implementation of the
//  Expression Tree ADT -- including the recursive helpers for the
//  public member functions
//
//  Instructor copy with the recursive helper function declarations.
//  The student version does not have those, but has a place to write
//  the declarations in the private section.
//
// --------------------------------------------------------------------

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

template<typename T>
class ExprTree {
	public:
		// Constructor
		ExprTree();
		ExprTree(const ExprTree &source);

		// Destructor
		~ExprTree();

		ExprTree& operator=(const ExprTree &source);

		// Expression tree manipulation operations
		void build();
		void expression() const;
		T evaluate() const;
		void clear();              // Clear tree
		void commute();
		bool isEquivalent(const ExprTree &source) const;
		bool isEmpty() const;

		// Output the tree structure -- used in testing/debugging
		void showStructure() const;

	private:
		class ExprTreeNode {
			public:
				// Constructor
				ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr);

				// Data members
				char dataItem;          // Expression tree data item
				ExprTreeNode *left;     // Pointer to the left child
				ExprTreeNode *right;    // Pointer to the right child
		};

		// Recursive helper functions for the public member functions -- insert
		// prototypes of these functions here.
		void buildHelper(ExprTreeNode* &p, string &str);
		void exprHelper(ExprTreeNode *p) const;
		T evalHelper(ExprTreeNode *p) const;
		void clearHelper(ExprTreeNode *&p);
		void showHelper(ExprTreeNode *p, int level) const;
		void copyHelper(ExprTreeNode* &to, const ExprTreeNode *from);
		void commuteHelper(ExprTreeNode *p);
		bool isEquivalentHelper(const ExprTreeNode *p, const ExprTreeNode *q) const;
		bool isOperator(const ExprTreeNode *p) const;

		// Data member
		ExprTreeNode *root;   // Pointer to the root node
};

#endif          // #ifndef EXPRESSIONTREE_H
