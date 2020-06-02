// finding all paths from a node to destination node in a graph

// source http://www.geeksforgeeks.org/find-paths-given-source-destination/ 

#include<iostream>
#include<list>
using namespace std;

class Graph {
	int noOfNodes_;
	list<int> *adj;
	void FindAllPaths(int, int, bool*, int&, int*);
  public:
	Graph(int v) : noOfNodes_(v) {
		adj = new list<int>[v];
	}

	void addEdge(int s, int d);
	void printAllPaths(int s, int d);
	
};

void Graph::addEdge(int s, int d) {
	adj[s].push_back(d);
}

void Graph::printAllPaths(int s, int d) {
	bool *isTracked = new bool[noOfNodes_];
	for(int i = 0; i < noOfNodes_; ++i) isTracked[i] = false;
	int *path = new int[noOfNodes_];
	int path_index = 0;

	FindAllPaths(s, d, isTracked, path_index, path);
}

void Graph::FindAllPaths(int s, int d, bool *isTracked, int &path_index, int *path) {

	isTracked[s] = true;
	path[path_index] = s;
	path_index++;
	if(s == d) {
		for(int i = 0; i <path_index; ++i) 
			cout << path[i] << "->" ;
		cout << endl;
	}

	else {
		for(list<int>::iterator itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
		if(!isTracked[*itr]) 
			FindAllPaths(*itr, d, isTracked, path_index, path);
		}
	}

	path_index--;
	isTracked[s] = false;
}


int main() {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
 
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;

    g.printAllPaths(2,3);

	return 0;
}
