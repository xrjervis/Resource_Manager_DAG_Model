#include "GraphCore.h"


Graph_adjacencyList::Graph_adjacencyList()
{
	VertexList.clear();
}


void Graph_adjacencyList::AddEdge(string name1, string name2)
{

	if (FindName(name1) < 0)
		CreateNode(name1);
	if (FindName(name2) < 0)
		CreateNode(name2);

	VNode *index_node;
	index_node = VertexList.at(FindName(name1)).nextVex;
	while (index_node != nullptr)
	{
		if (index_node->nodeName == name2)
			return;
		index_node = index_node->nextVex;
	}
	VNode *e = new VNode;
	e->nodeName = name2;
	e->nextVex = VertexList.at(FindName(name1)).nextVex;
	VertexList.at(FindName(name1)).nextVex = e;
}

//if find name, return its index of vector; otherwise return -1
int Graph_adjacencyList::FindName(string name)
{
	for (auto iter = VertexList.begin(); iter != VertexList.end(); ++iter)
	{
		if (iter->nodeName == name)
			return iter - VertexList.begin();
	}
	return -1;
}

void Graph_adjacencyList::CreateNode(string name)
{
	VNode node;
	node.nodeName = name;
	node.nextVex = nullptr;
	VertexList.push_back(node);
}

void Graph_adjacencyList::DeleteNode(string name)
{
	deque<string> delWaitQueue;
	//If the name of the node exist, then add it to delete queue
	if (FindName(name) >= 0)
	{
		delWaitQueue.push_back(name);

		//when the program find another node relies on this deleting node, 
		//then add it to delete queue as well
		//until the delete queue is empty
		while (!delWaitQueue.empty())
		{
			string delNodeName = delWaitQueue.front();
			for (auto i = VertexList.begin(); i != VertexList.end(); )
			{
				//delte the current node in the vertex list
				VNode *index_node;
				if (i->nodeName == delNodeName)
				{
					unusableVertexList.push_back(i->nodeName); // add into the unusable list

					//release memeory for the nodes rely on to prevent memory leak
					index_node = i->nextVex;
					while (index_node != nullptr)
					{
						VNode *temp;
						temp = index_node->nextVex;
						delete index_node;
						index_node = temp;
					}
					i = VertexList.erase(i);	//remove the head node from vertexlist
					delWaitQueue.pop_front();   //remove the node from the front positon of delete queue
				}
				else
				{
					//find whether there exists any other nodes rely on the deleting node
					index_node = i->nextVex;
					while (index_node != nullptr)
					{

						if (index_node->nodeName == delNodeName)
						{
							if (find(delWaitQueue.begin(), delWaitQueue.end(), i->nodeName) == delWaitQueue.end())
							{
								delWaitQueue.push_back(i->nodeName);	 //add the node that rely on index_node to the delete queue
							}
							break;
						}
						index_node = index_node->nextVex;
					}// end while
					++i;
				}// end if	
			}// end for
		}// end while
		cout << "The node has been deleted successfully!" << endl;
		cout << endl;
		//All node delete. Draw .svg file
		DrawSVG();		

		SaveGraph();
	}
	else
	{
		cout << "This node doesn't exist, please try again!" << endl;
		cout << endl;
	}
}

void Graph_adjacencyList::DrawSVG()
{
	vector<node> nodeList;
	VNode *index_node;
	Graph G;
	GraphAttributes GA(G, GraphAttributes::nodeGraphics |
		GraphAttributes::edgeGraphics |
		GraphAttributes::nodeLabel |
		GraphAttributes::nodeStyle |
		GraphAttributes::edgeStyle); // Create graph attributes for this graph

	for (auto i = VertexList.begin(); i != VertexList.end(); ++i)
	{
		node n = G.newNode();
		GA.height(n) = 15;
		GA.width(n) = 15 * i->nodeName.length();
		GA.label(n) = i->nodeName;
		nodeList.push_back(n);
	}

	for (auto i = VertexList.begin(); i != VertexList.end(); ++i)
	{
		index_node = i->nextVex;

		while (index_node != nullptr)
		{
			edge e = G.newEdge(nodeList.at(FindName(i->nodeName)), nodeList.at(FindName(index_node->nodeName)));
			//cout << i->nodeName << " ---> " << index_node->nodeName << endl;
			index_node = index_node->nextVex;
		}
	}
	node n;
	forall_nodes(n, G) {   // iterate through all the node in the graph
		GA.fillColor(n) = Color("#FFFF00"); // set node color to yellow
	}
	ogdf_SetLayout(&GA);
	GraphIO::drawSVG(GA, "resource_graph.svg");
}

void Graph_adjacencyList::SaveGraph()
{
	VNode *index_node;
	ofstream out("save.dat");
	if (out)
	{
		for (auto it = VertexList.begin(); it != VertexList.end(); ++it)
		{
			index_node = it->nextVex;
			while (index_node != nullptr)
			{
				out << it->nodeName << " " << index_node->nodeName << endl;
				index_node = index_node->nextVex;
			}
		}
		cout << endl;
		cout << "Current Graph Saved." << endl;
		cout << endl;
	}
}

void InitGraph(string filename)
{
	Graph_adjacencyList *gaList = &Graph_adjacencyList::GetInstance(); // Singleton test = Singleton::geInstance();这种情况出现时，编译报错。
	string name1, name2;
	ifstream in(filename);
	if (!in)
	{
		cout << filename << " doesn't exist." << endl;
		return;
	}
	while (in >> name1 >> name2)
	{
		//cout << name1 << " " << name2 << endl;
		if (name1 != name2)
			gaList->AddEdge(name1, name2);
	}
	cout << "Read successfully!\n" << endl;
	in.close();  //close file
	cout << "Start drawing graph, please wait......" << endl;
	gaList->DrawSVG();  //Call DrawSVG Function to generate a .svg file
	cout << "The .svg file has been created successfully!" << endl;
	cout << endl;
	gaList->SaveGraph();
}

void InitGraph(string name1, string name2)
{
	Graph_adjacencyList *gaList = &Graph_adjacencyList::GetInstance();
	if (name1 != name2)
	{
		gaList->AddEdge(name1, name2);
		cout << name1 << " and " << name2 << " have been added!\n" << endl;

		//Call DrawSVG Function to generate a .svg file
		gaList->DrawSVG();
		gaList->SaveGraph();
	}
	else
	{
		cout << "You enter two same node. Please note that a resource node cannot rely on itself." << endl;
	}
}
