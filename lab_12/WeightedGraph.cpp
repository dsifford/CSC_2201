// --------------------------------------------------------------------
//
//  Laboratory 12                                    WeightedGraph.cpp
//
// --------------------------------------------------------------------

#ifndef WEIGHTEDGRAPH_CPP
#define WEIGHTEDGRAPH_CPP

#include "WeightedGraph.h"
#include "config.h"

// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
WeightedGraph::WeightedGraph(int maxNumber) {}

// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
WeightedGraph::WeightedGraph(const WeightedGraph &other) {}

// Copies from another WeightedGraph.
WeightedGraph& WeightedGraph::operator=(const WeightedGraph &other) {
	return *this;
}

// Frees the memory used by a graph.
WeightedGraph::~WeightedGraph() {}

// Inserts newVertex into a graph. If a vertex with the same label
// as newVertex already exists in the graph, then updates that
// vertex's data with newVertex's data.
void WeightedGraph::insertVertex(const Vertex &newVertex) {}

// Insert an edge with the specified weight between vertices
// v1 and v2.
void WeightedGraph::insertEdge(const string &v1, const string &v2, int wt) {}

// Searches a graph for vertex v. If the vertex is found, then copies
// the vertex data to vData and returns 1. Otherwise, returns 0 with
// vData undefined.
bool WeightedGraph::retrieveVertex(const string &v, Vertex &vData) const {
	return false;
}

// If there is an edge connecting vertices v1 and v2, then returns 1
// with wt returning the weight of the edge. Otherwise, returns 0
// with wt undefined.
bool WeightedGraph::getEdgeWeight(const string &v1, const string &v2, int &wt) const {
	return false;
}

// Removes vertex v from a graph.
void WeightedGraph::removeVertex(const string &v) {}

// Removes the edge between vertices v1 and v2 from a graph.
void WeightedGraph::removeEdge(const string &v1, const string &v2) {}

// Removes all the vertices and edges from a graph.
void WeightedGraph::clear() {}

// Returns 1 if a graph is empty. Otherwise, returns 0.
bool WeightedGraph::isEmpty() const {
	return false;
}

// Returns 1 if a graph is full. Otherwise, returns 0.
bool WeightedGraph::isFull() const {
	return false;
}

// Outputs a graph's vertex list and adjacency matrix. This operation
// is intended for testing/debugging purposes only.
void WeightedGraph::showStructure() const {
	if (size == 0) {
		cout << "Empty graph" << endl;
	}
	else {
		cout << endl << "Vertex list : " << endl;
		for (int row = 0; row < size; row++) {
			cout << row << '\t' << vertexList[row].getLabel();
#if LAB12_TEST2
			cout << '\t' << vertexList[row].getColor();
#endif
			cout << endl;
		}

		cout << endl << "Edge matrix : " << endl << '\t';
		for (int col = 0; col < size; col++) {
			cout << col << '\t';
		}
		cout << endl;
		for (int row = 0; row < size; row++) {
			cout << row << '\t';
			for (int col = 0; col < size; col++) {
				int wt = getEdge(row, col);
				if (wt == INFINITE_EDGE_WT) {
					cout << "- \t";
				}
				else {
					cout << wt << '\t';
				}
			}
			cout << endl;
		}
	}
}

// --------------------------------------------------------------------
//
//  Facilitator functions
//

// Returns the adjacency matrix index for vertex v. Returns size if
// the vertex does not exist.
int WeightedGraph::getIndex(const string &v) const {
	return -1;
}

// Gets adjMatrix[row][col].
int WeightedGraph::getEdge(int row, int col) const {
	return -1;
}

// sets adjMatrix[row][col].
void WeightedGraph::setEdge(int row, int col, int wt) {}

#endif
