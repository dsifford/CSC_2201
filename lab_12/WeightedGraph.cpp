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
WeightedGraph::WeightedGraph(int maxNumber) {
	maxSize = maxNumber;
	size = 0;
	adjMatrix = new int[maxSize * maxSize];
	vertexList = new Vertex[maxSize];
}

// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
WeightedGraph::WeightedGraph(const WeightedGraph &other) {
	maxSize = other.maxSize;
	size = other.size;
	adjMatrix = new int[maxSize * maxSize];
	vertexList = new Vertex[maxSize];
	for (int i = 0; i < (size * size); i++) {
		if (i < size) {
			vertexList[i] = other.vertexList[i];
		}
		adjMatrix[i] = other.adjMatrix[i];
	}
}

// Copies from another WeightedGraph.
WeightedGraph& WeightedGraph::operator=(const WeightedGraph &other) {
	maxSize = other.maxSize;
	clear();
	size = other.size;
	adjMatrix = new int[maxSize * maxSize];
	vertexList = new Vertex[maxSize];
	for (int i = 0; i < (size * size); i++) {
		if (i < size) {
			vertexList[i] = other.vertexList[i];
		}
		adjMatrix[i] = other.adjMatrix[i];
	}
	return *this;
}

// Frees the memory used by a graph.
WeightedGraph::~WeightedGraph() {
	clear();
	adjMatrix = NULL;
	vertexList = NULL;
}

// Inserts newVertex into a graph. If a vertex with the same label
// as newVertex already exists in the graph, then updates that
// vertex's data with newVertex's data.
void WeightedGraph::insertVertex(const Vertex &newVertex) {
	int index, toAdd, addIndex;
	
	if (isFull()) {
		throw logic_error("Graph is full");
	}
	
	index = getIndex(newVertex.getLabel());
	if (index != size) {
		vertexList[index].setLabel(newVertex.getLabel());
		vertexList[index].setColor(newVertex.getColor());
		return;
	}

	size++;
	vertexList[index] = newVertex;
	toAdd = size - 1;
	addIndex = size * size - size - 1;

	for (int i = addIndex; i >= 0; i--) {
		if (toAdd == 0) break;
		if (i == addIndex) {
			adjMatrix[i] = -1;
			toAdd--;
			addIndex -= size;
			continue;
		}
		adjMatrix[i] = adjMatrix[i - toAdd];
	}
}

// Insert an edge with the specified weight between vertices
// v1 and v2.
void WeightedGraph::insertEdge(const string &v1, const string &v2, int wt) {
	int i = getIndex(v1);
	int j = getIndex(v2);
	if (i == size || j == size) {
		throw logic_error("One or more vertices not found");
	}
	setEdge(i, j, wt);
	setEdge(j, i, wt);
}

// Searches a graph for vertex v. If the vertex is found, then copies
// the vertex data to vData and returns 1. Otherwise, returns 0 with
// vData undefined.
bool WeightedGraph::retrieveVertex(const string &v, Vertex &vData) const {
	bool found = false;
	for (int i = 0; i < maxSize; i++) {
		if (vertexList[i].getLabel() == v) {
			vData = vertexList[i];
			found = true;
			break;
		}
	}
	return found;
}

// If there is an edge connecting vertices v1 and v2, then returns 1
// with wt returning the weight of the edge. Otherwise, returns 0
// with wt undefined.
bool WeightedGraph::getEdgeWeight(const string &v1, const string &v2, int &wt) const {
	int index1 = getIndex(v1);
	int index2 = getIndex(v2);
	if (index1 == size || index2 == size) {
		throw logic_error("One or more vertices not found");
	}
	wt = getEdge(index1, index2);	
	return wt != -1;
}

// Removes vertex v from a graph.
void WeightedGraph::removeVertex(const string &v) {
	int index, i, numRemoved, removalIndex;
	index = getIndex(v);
	if (index == size) {
		throw logic_error("Vertex not found");
	}

	for (i = (index * size); i < (size * size); i++) {
		if (i >= size * size - size) {
			adjMatrix[i] = -1;
		}
		else {
			adjMatrix[i] = adjMatrix[i + size];
		}
	}	

	removalIndex = index;
	numRemoved = 0;
	for (i = index; i < (size * size - size); i++) {
		if (i == removalIndex) {
			numRemoved++;
			removalIndex += size - 1;
		}
		adjMatrix[i] = adjMatrix[i + numRemoved];
	}

	for (i = index; i < size - 1; i++) {
		vertexList[i] = vertexList[i + 1];
	}

	size--;
}

// Removes the edge between vertices v1 and v2 from a graph.
void WeightedGraph::removeEdge(const string &v1, const string &v2) {
	int i = getIndex(v1);
	int j = getIndex(v2);
	if (i == size || j == size) {
		throw logic_error("One or more vertices not found");
	}
	setEdge(i, j, -1);
	setEdge(j, i, -1);
}

// Removes all the vertices and edges from a graph.
void WeightedGraph::clear() {
	delete [] adjMatrix;
	delete [] vertexList;
	size = 0;
	adjMatrix = new int[maxSize];
	vertexList = new Vertex[maxSize];
}

// Returns 1 if a graph is empty. Otherwise, returns 0.
bool WeightedGraph::isEmpty() const {
	return size == 0;
}

// Returns 1 if a graph is full. Otherwise, returns 0.
bool WeightedGraph::isFull() const {
	return size == maxSize;
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

/**
 * Helper functions
 */

// Converts vertex label to an adjacency matrix index. Returns size if label is
// not found.
int WeightedGraph::getIndex(const string &v) const {
	int index = size;
	for (int i = 0; i < size; i++) {
		if (vertexList[i].getLabel() == v) {
			index = i;
			break;
		}
	}
	return index;
}

// Gets adjMatrix[row][col].
// NOTE: row & col are both 0-based indices
int WeightedGraph::getEdge(int row, int col) const {
	int i = adjMatrix[row * size + col];
	return i ? i : -1;
}

// sets adjMatrix[row][col].
// NOTE: row & col are both 0-based indices
void WeightedGraph::setEdge(int row, int col, int wt) {
	adjMatrix[row * size + col] = wt;
}

#endif
