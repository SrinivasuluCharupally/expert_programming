// BFS for graph..

// source 

#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
	int noOfNodes;
	list<int>* adj;
  public:
	Graph(int n) :noOfNodes(n) {
		adj = new list<int>[n];
	}

	void addEdge(int s, int d) {
		adj[s].push_back(d);
	}


	void BFS(int node) {
		queue<int> myqueue; // DFS use stack , every thing else same
		myqueue.push(node);
		bool isTracked[noOfNodes];
		for(int i =0; i < noOfNodes; ++i) isTracked[noOfNodes]= false;
		while(!myqueue.empty()) {
			int s = myqueue.front();
			myqueue.pop();
			if(!isTracked[s]) {
				cout << s << " " ;
				isTracked[s] = true;
			}

			for(list<int>::iterator itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
				if(!isTracked[*itr]) {
					myqueue.push(*itr);
		//			isTracked[*itr] = true;
				}
			}
		}
	}
};
	




int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	g.BFS(0);
}
