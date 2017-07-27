// --------------------------------------------------------------------
//
//  Laboratory 12                                      WeightedGraph.h
//
//  Class declaration for the adjacency matrix implementation of
//  the Weighted Graph ADT
//
// --------------------------------------------------------------------

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <stdexcept>
#include <iostream>
#include <climits> // for INT_MAX
#include <string>  // for labels
using namespace std;

class WeightedGraph {
	public:
		static const int MAX_GRAPH_SIZE = 10;         // Default number of vertices
		static const int INFINITE_EDGE_WT = INT_MAX;  // "Weight" of a missing edge

		class Vertex {
			public:
				void setLabel(const string &newLabel) { label = newLabel; }
				string getLabel() const { return label; }
				void setColor(char newColor) { color = newColor; }
				char getColor() const { return color; }

			private:
				string label;
				char color;
		};

		// --------------------------------------------------------------------

		// Constructors
		WeightedGraph(int maxNumber = MAX_GRAPH_SIZE);
		WeightedGraph(const WeightedGraph &other);

		// Overloaded assignment operator
		WeightedGraph& operator=(const WeightedGraph &other);

		// Destructor
		~WeightedGraph();

		// Graph manipulation operations
		void insertVertex(const Vertex &newVertex);
		void insertEdge(const string &v1, const string &v2, int wt);
		bool retrieveVertex(const string &v, Vertex &vData) const;

		// Get vertex
		bool getEdgeWeight(const string &v1, const string &v2, int &wt) const;
		void removeVertex(const string &v);
		void removeEdge(const string &v1, const string &v2);
		void clear();

		// Graph status operations
		bool isEmpty() const;
		bool isFull() const;

		// Output the graph structure -- used in testing/debugging
		void showStructure() const;

		// Programming exercise operations
		void showShortestPaths() const;
		bool hasProperColoring() const;
		bool areAllEven() const;

	private:
		// Helper functions
		int getIndex(const string &v) const;    // Converts vertex label to an adjacency matrix index
		int getEdge(int row, int col) const;    // Get edge weight using  adjacency matrix indices
		void setEdge(int row, int col, int wt); // Set edge weight using adjacency matrix indices

		// Data members
		int maxSize; // Maximum number of vertices in the graph
		int size;    // Actual number of vertices in the graph
		int *adjMatrix;
		Vertex *vertexList;
};

#endif
