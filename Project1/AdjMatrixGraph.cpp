

#include "AdjMatrixGraph.h"
#include <string>
#include <iomanip>

	//Default Constructor
AdjMatrixGraph::AdjMatrixGraph() : numVerticies(0), capacity(CAP) {
		verticies = new string[capacity]();
		matrix = new int*[capacity]();
	}

	//Overloaded Constructor
	AdjMatrixGraph::AdjMatrixGraph(int numVerticies) : numVerticies(numVerticies), capacity(numVerticies * 2) {
		verticies = new string[capacity]();
		matrix = new int*[capacity]();
	};

	//Overloaded Copy Constructor
	AdjMatrixGraph::AdjMatrixGraph(const AdjMatrixGraph& other) {
		capacity = other.capacity;
		numVerticies = other.numVerticies;

		verticies = new string[capacity];
		for (int i = 0; i < numVerticies; i++) {
			verticies[i] = other.verticies[i];
		}

		matrix = new int*[capacity];
		for (int i = 0; i < numVerticies; i++) {
			for (int j = 0; j < numVerticies; j++) {
				verticies[i][j] = other.verticies[i][j];
			}
		}
	}

	//Overloaded Move Constructor
	AdjMatrixGraph::AdjMatrixGraph(AdjMatrixGraph&& other) {
		capacity = other.capacity;
		numVerticies = other.numVerticies;

		verticies = other.verticies;
		matrix = other.matrix;
		
		other.verticies = nullptr;
		other.matrix = nullptr;
		other.capacity = 0;
		other.numVerticies = 0;
	}

	// Overrided Assignement Operator
	AdjMatrixGraph& AdjMatrixGraph::operator=(const AdjMatrixGraph& other) {
		if (&other != this) {
			if(cap)
		}
		else cerr << "Incorrect attempt to assign matrix to itself" << endl;

	}

	//Overrided Move Assignemnt Operator
	AdjMatrixGraph& AdjMatrixGraph::operator=(AdjMatrixGraph&& other) {

	}

	//NumVerticies Getter
	int getNumOfVertices() const {

	}

	//Capacity Getter
	int getMaxVertices() const {

	}

	//Traverse method
	vector<string> traverse() const {

	}

	//CreateGraph Method
	void AdjMatrixGraph::createGraph(const vector<vector<string>> data) {
		//Looping through rows of data
		for (int i = 0; i < data.size(); i++) {
			//Looping through cols of data
			for (int j = 1; j < data.at(i).size(); j++) {
				//Looping through vertices
				for (int k = 0; k < numVerticies; k++) {
					//If vertex is found
					if (verticies[k] == data.at(i).at(k))
						//Set the element in the matrix to 1
						matrix[k][i] = 1;
				}
			}
		}
	}

	/

	//Insert Vertex Method
	void AdjMatrixGraph::insert(const string& vertex, const vector<string> predecessors, const vector<string> successors) {

	}

	//Destructor
	AdjMatrixGraph::~AdjMatrixGraph() {

	}

	//Print Method
	ostream& operator<<(ostream& out, const AdjMatrixGraph& matrix) {

	}
