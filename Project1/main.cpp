
/*
Badajoz, Severiano

CS A200
March 11, 2018

Lab 04
*/

#include <iostream>
#include <string>
#include <vector>
#include "AdjMatrixGraph.h"

int main()
{
	cout << " ______________________ Graph g1: ______________________ " << endl;
	vector<vector<string>> data1 =
	{
		{ "A", "B", "F" },
	{ "B", "C", "D", "F" },
	{ "C", "E" },
	{ "D" },
	{ "E", "D", "F" },
	{ "F", "D" }
	};

	//overloaded constructor
	AdjMatrixGraph g1 = AdjMatrixGraph(data1.size());
	g1.createGraph(data1);
	//Overloaded Insertion operator
	cout << g1;
	cout << " ______________________ Graph g2: ______________________ " << endl;
	vector<vector<string>> data2 =
	{
	{ "A", "C", "D" },
	{ "B", "E" },
	{ "C", "A", "E" },
	{ "D" },
	{ "E", "F" }
	};
	//default constructor
	AdjMatrixGraph g2;
	g2.createGraph(data2);
	cout << g2;

	//overloaded assignment op.
	cout << " ______________________ Graph g2 = g1: ______________________ " << endl;
	g2 = g1;
	cout << g2;

	//copy constructor
	cout << " ______________________ Graph g3 = AdjMatrixGraph(g1): ______________________ " << endl;
	AdjMatrixGraph g3 = AdjMatrixGraph(g1);
	cout << g3;

	//insert
	cout << " ______________________ g3.insert(L, { A, B }, { H, Z }): ______________________ " << endl;
	g3.insert("L", { "A", "B" }, { "H", "Z" });
	cout << g3;

	//move constructor
	cout << " ______________________ AdjMatrixGraph g4 = move(g3): ______________________ " << endl;
	AdjMatrixGraph g4 = move(g3);
	cout << g4;

	//move assignment operator
	cout << " ______________________ g5 = move(g3);: ______________________ " << endl;
	AdjMatrixGraph g5;
	g5 = move(g3);
	cout << g5;

	emptyGraph
	cout << " ______________________ 	g4.emptyGraph(): ______________________ " << endl;
	g4.();
	cout << g4;
	


	system("Pause");
	return 0;
}