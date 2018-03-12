/*
Badajoz, Severiano

CS A200
March 11, 2018

Lab 04
*/

#include "AdjMatrixGraph.h"
#include <string>
#include <iomanip>

	//Default Constructor
AdjMatrixGraph::AdjMatrixGraph() : numVerticies(0), capacity(CAP) {
		verticies = new string[capacity]();
		matrix = new int*[capacity];
		for (int i = 0; i < capacity; i++)
			matrix[i] = new int[capacity]();
	}

	//Overloaded Constructor
	AdjMatrixGraph::AdjMatrixGraph(int cap) : numVerticies(0), capacity(cap * 2) {
		verticies = new string[capacity]();
		matrix = new int*[capacity];
		for (int i = 0; i < capacity; i++)
			matrix[i] = new int[capacity]();
	};

	//Overloaded Copy Constructor
	AdjMatrixGraph::AdjMatrixGraph(const AdjMatrixGraph& other) {
		capacity = other.capacity;
		numVerticies = other.numVerticies;

		verticies = new string[capacity];
		matrix = new int*[capacity];
		for (int i = 0; i < capacity; ++i)
		{
			verticies[i] = other.verticies[i];
			matrix[i] = new int[capacity];
			for (int j = 0; j < capacity; ++j)
				matrix[i][j] = other.matrix[i][j];
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
			if (capacity != other.capacity) {
				for (int i = 0; i < capacity; i++) {
					delete[] matrix[i];
					matrix[i] = nullptr;
				}
				capacity = other.capacity;

				delete[] matrix;
				matrix = new int*[capacity];

				for (int i = 0; i < capacity; i++)
					matrix[i] = new int[capacity];

				delete[] verticies;
				verticies = new string[capacity];
			}

			numVerticies = other.numVerticies;
			for(int i = 0; i < capacity; i++) {
				verticies[i] = other.verticies[i];
				for (int j = 0; j < capacity; j++)
					matrix[i][j] = other.matrix[i][j];

			}
		}
		else cerr << "Incorrect attempt to assign matrix to itself" << endl;

		return *this;
	}

	//Overrided Move Assignemnt Operator
	AdjMatrixGraph& AdjMatrixGraph::operator=(AdjMatrixGraph&& other) {
		if (&other != this) {
			delete[] verticies;
			verticies = other.verticies;

			for (int i = 0; i < capacity; i++) {
				delete[] matrix[i];
				matrix[i] = nullptr;
			}

			delete matrix;
			matrix = other.matrix;
			numVerticies = other.numVerticies;
			capacity = other.capacity;

			other.numVerticies = 0;
			other.capacity = 0;
			other.verticies = nullptr;
			other.matrix = nullptr;
		}
		return *this;
	}

	//NumVerticies Getter
	int AdjMatrixGraph::getNumVerticies() const {
		return numVerticies;
	}

	//Capacity Getter
	int AdjMatrixGraph::getCapactiy() const {
		return capacity;
	}

	//Traverse method
	vector<string> AdjMatrixGraph::traverse() const {
		vector<string> ret;
		for (int i = 0; i < numVerticies; i++)
			ret.push_back(verticies[i]);
		return ret;
	}

	//Empty Method
	void AdjMatrixGraph::emptyGraph() {
		delete[] verticies;
		verticies = new string[capacity]();
		for (int i = 0; i < numVerticies; ++i) {
			delete[] matrix[i];
			matrix[i] = new int[capacity]();
		}

		numVerticies = 0;
	}

	//CreateGraph Method
	void AdjMatrixGraph::createGraph(const vector<vector<string>> data) {
		if (numVerticies == 0) {
			if (data.size() <= capacity) {
				//Looping through rows of data
				for (vector<string> vec: data) {
					//index trackers
					int vertexNum = 0;	
					int succNum = 0; 
					//Looping through cols of data
					for (string succ : vec) {
						bool found = false;
						//Looping through vertices
						for (int i = 0; i < numVerticies && !found; i++) {
							//If vertex is found
							if (verticies[i] == succ) {
								found = true;
								if (succ == vec.at(0))
									vertexNum = i;
								else succNum = i;
							}
						}
						if (!found) {
							verticies[numVerticies] = succ;
							if (succ == vec.at(0))
								vertexNum = numVerticies++;
							else succNum = numVerticies++;
						}
						if (succ != vec.at(0))
							matrix[vertexNum][succNum] = 1;
					}
				}
			}
			else cerr << "Incorrect attempt to use data with more verticies than capacity" << endl;
		}
		else cerr << "Cannot use createGraph on a non-empty graph" << endl;
	}

	

	//Insert Vertex Method
	void AdjMatrixGraph::insert(const string& vertex, const vector<string> predecessors, const vector<string> successors) {
		if (numVerticies < capacity) {
			verticies[numVerticies] = vertex;
			for (string predecessor : predecessors) {
				int num = 0;
				bool found = false;
				for (int i = 0; i < numVerticies && !found; i++) {
					if (verticies[i] == predecessor) {
						found = true;
						num = i;
					}
				}
				matrix[num][numVerticies] = 1;
			}
			for (string successor : successors) {
				int num = 0;
				bool found = false;
				for (int i = 0; i < numVerticies && !found; i++) {
					if (verticies[i] == successor) {
						found = true;
						num = i;
					}
				}
				matrix[numVerticies][num] = 1;
			}
			numVerticies++;
		}
		else cerr << "Incorrect attempt to add a vertex into a saturated matrix" << endl;
	}

	//Destructor
	AdjMatrixGraph::~AdjMatrixGraph() {
		for (int i = 0; i < capacity; ++i)
		{
			delete[] matrix[i];
			matrix[i] = nullptr;
		}

		delete[] matrix;
		matrix = nullptr;
		delete[] verticies;
		verticies = nullptr;
		numVerticies = 0;
		capacity = 0;
	}

	//Print Method
	ostream& operator<<(ostream& out, const AdjMatrixGraph& matrix) {
		if (matrix.numVerticies > 0)
		{
			for (int i = 0; i < matrix.numVerticies; i++)
			{
				out << matrix.verticies[i] << " -> [";
				for (int j = 0; j < matrix.numVerticies; j++)
					if (matrix.matrix[i][j] > 0)
						out << matrix.matrix[i][j] << " ";
				out << "\b]\n";//backspace operator to remove unnecessary space at the end of the for loop
			}
			
		}
		else out << "EMPTY" << endl;

		return out;
	}
