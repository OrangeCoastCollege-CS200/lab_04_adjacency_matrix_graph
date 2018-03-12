#ifndef ADJMATRIXGRAPH_H
#define ADJMATRIXGRAPH_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

const int CAP = 20;

class AdjMatrixGraph {
	//Print Method
	friend ostream& operator<<(ostream& out, const AdjMatrixGraph& matrix);
public:
	//Default Constructor
	AdjMatrixGraph();

	//Overloaded Constructor
	AdjMatrixGraph(int cap);

	//Overloaded Copy Constructor
	AdjMatrixGraph(const AdjMatrixGraph& other);

	//Overloaded Move Constructor
	AdjMatrixGraph(AdjMatrixGraph&& other);

	//Overrided Assignement Operator
	AdjMatrixGraph& operator=(const AdjMatrixGraph& other);

	//Overrided Move Assignemnt Operator
	AdjMatrixGraph& operator=(AdjMatrixGraph&& other);

	//NumVerticies Getter
	int getNumVerticies() const;

	//Capacity Getter
	int getCapactiy() const;

	//Traverse method
	vector<string> traverse() const;

	//CreateGraph Method
	void createGraph(const vector<vector<string>> data);


	//Insert Vertex Method
	void insert(const string& vertex, const vector<string> predecessors, const vector<string> successors);

	//Destructor
	~AdjMatrixGraph();

private:
	string * verticies;
	int ** matrix;
	int numVerticies;
	int capacity;
};




#endif