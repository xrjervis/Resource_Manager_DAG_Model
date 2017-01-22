This program is implemented by C++ with [OGDF - Open Graph Drawing Framework](http://amber-v7.cs.tu-dortmund.de/doku.php/start)

Source codes can be seen on my [Github](https://github.com/xrjervis/Resource_Manager_DAG_Model)

#### Features:

* Automatically read from save.dat (saved modified graph before) if exists.
* Input ‘1’, read from resource.txt.
* Input ‘2’, add a link between two nodes manually.
* Input ‘3’, delete a node.
* Input ‘4’, show the usable and unusable nodes.
* Input ‘q’, exit the program.
* All the add and delete operation can be saved to save.dat.
* The current view of the graph is stored in the resource_graph.svg file.

#### Description:

###### Main.cpp
The entrance of the program.

###### GraphCore.cpp
It includes the core functions to generate the graph of the nodes and links. I use adjacency list to store each node and links. The functions include AddEdge, FindName, CreateNode, DeleteNode, DrawSVG, SaveGraph, InitGraph.etc. 

###### OGDF.cpp
It links to the OGDF library, and the function ogdf_SetLayout is to arrange the layout of the graph.

###### ConsoleControl.cpp
It output the instructions and deals with the input from console.

#### Screenshots
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_1.png)
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_2.png)
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_3.png)
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_4.png)
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_5.png)
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_6.png)
![](http://7xtifo.com1.z0.glb.clouddn.com/RM_OGDF_7.png)