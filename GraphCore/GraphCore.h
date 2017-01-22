#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include "OGDF.h"
using namespace std;


// Adjacency List
class Graph_adjacencyList
{
private: // Internal Class 
	// represent each node
	class VNode
	{
	public:
		string nodeName;   
		VNode *nextVex;   // points to the node it refers to
	};

private:

	Graph_adjacencyList();
	~Graph_adjacencyList() {};
	Graph_adjacencyList(const Graph_adjacencyList&);              // Don't need to Implement
	void operator=(const Graph_adjacencyList&);                   // Don't need to implement
	
	

public:
	//C++ Design Model Singleton
	static Graph_adjacencyList& GetInstance()
	{
		static Graph_adjacencyList instance;
		return instance;
	}

	void AddEdge(string name1, string name2);
	int FindName(string name);
	void CreateNode(string name);
	void DeleteNode(string name);
	void DrawSVG();
	void SaveGraph();

	vector<VNode> VertexList;            //All nodes are stored in this vector
	vector<string> unusableVertexList;
};

void InitGraph(string filename);
void InitGraph(string name1, string name2);
