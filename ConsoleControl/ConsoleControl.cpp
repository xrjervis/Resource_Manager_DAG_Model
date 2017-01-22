#include "ConsoleControl.h"

void Init()
{
	InitGraph("save.dat");
	DrawWelcomePanel();
	InputControl();
}

void DrawWelcomePanel()
{
	cout << endl;
	cout << "                                    Instructions                                    " << endl;
	cout << "====================================================================================" << endl;
	cout << endl;
	cout << "   NOTE: The current graph view can be found as a .svg file under the folder.       " << endl;
	cout << endl;
	cout << "         Any modification will be saved and will be automatically read next time.   " << endl;
	cout << "         If you don't want the program read the modification made last time, just   " << endl;
	cout << "         delete the save.dat file under the folder.                                 " << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "   1. Read from resource.txt, which should be put into the folder of this program.  " << endl;
	cout << endl;
	cout << "   2. Input two resource nodes manually.                                            " << endl;
	cout << endl;
	cout << "   3. Delete an existing node.                                                      " << endl;
	cout << endl;
	cout << "   4. Show current list. (Usable or not)                                            " << endl;
	cout << endl;
	cout << "   5. Exit program.                                                                 " << endl;
	cout << endl;
	cout << "====================================================================================" << endl;
	cout << endl;
	cout << "               Made by Rui Xie, from 01/16/2017 to 01/19/2017                       " << endl;
	cout << endl;
	cout << "====================================================================================" << endl;
	cout << endl;
}

void InputControl()
{
	while (1)
	{
		cout << "Please Input Your Choice:(1 - 5): ";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			ReadFromFile("resource.txt");
			break;
		case '2':
			ReadFromLine();
			break;
		case '3':
			DeleteNode();
			break;
		case '4':
			ShowUnusableList();
			break;
		case 'q':
			cout << "Program Exit!" << endl;
			return;
			break;
		default:
			cout << "Invalid Input. Try Again!" << endl;
			cin.clear();         //to ignore '\n' 
			cin.ignore();
			break;
		}
	}	
}

void ReadFromFile(string filename)
{
	InitGraph(filename);
}

void ReadFromLine()
{
	string name1, name2;
	cout << "Please input two nodes (eg. handgun bullets) : ";
	cin >> name1 >> name2;
	InitGraph(name1, name2);
}

void DeleteNode()
{
	string nodename;
	Graph_adjacencyList *gaList = &Graph_adjacencyList::GetInstance();
	cout << "Please input the node name to delete: ";
	cin >> nodename;
	gaList->DeleteNode(nodename);
}

void ShowUnusableList()
{
	Graph_adjacencyList *gaList = &Graph_adjacencyList::GetInstance();
	cout << endl;
	cout << "                                    Unusable List                                   " << endl;
	cout << "====================================================================================" << endl;
	cout << endl;
	for each (auto obj in gaList->VertexList)
	{
		if (find(gaList->unusableVertexList.begin(), gaList->unusableVertexList.end(), obj.nodeName) == gaList->unusableVertexList.end())
			cout << "               " << obj.nodeName << "\t" << "Usable                              " << endl;
	}
	for each (auto obj in gaList->unusableVertexList)
	{
		cout << "               " << obj << "\t" << "Unusable                              " << endl;
	}
	cout << endl;
	cout << endl;
	cout << "====================================================================================" << endl;
	cout << endl;
}
