// BFS for graph, recursive 
// use queue


#include<iostream>
#include<list>
using namespace std;

class Graph{
	int noOfNodes;
	list<int> *adj;
  public:
	Graph(int n) {
		noOfNodes = n;
		adj = new list<int>[n];
	}

	void addEdge(int s, int d) {
		adj[s].push_back(d);
	}

	void BFS(int node) {
		bool* isTracked = new bool[noOfNodes];
		for(int i =0; i < noOfNodes; ++i) isTracked[i] = false;

		BFSUtils(node, isTracked);
	}

	void BFSUtils(bool* isTracked, queue<int> &queue_) {
		if(!isTracked[queue_->top()]) { // this for checking if the same node exit multiple times, should not exclude ...
		isTracked[queue_->top()] = true;
		cout << queue_->top() << " "; }

		for(list<int>::iterator itr = adj[queue_->top()].begin(); itr != adj[queue_->top()].end(); ++itr) {
			if(!isTracked[*itr]) {
			queue_->push(*itr);
			//BFSUtils(*itr, isTracked);
			}
		}
		queue_->pop();
		BFSUtils(queue_->top(), isTracked, queue_)
	}

	void BFS_disconnected_graph() {
		bool* isTracked = new bool[noOfNodes];
		for(int i = 0; i < noOfNodes; ++i) isTracked[i] = false;
		cout << endl << "For disconnected graphs.." << endl;
		queue<int> queue_;
		for(int i = 0; i < 4; ++i) 
			if(!isTracked[i]) {
				queue_->push(i); 
				BFSUtils(  isTracked, queue_);
			}
		cout << endl;
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
    g.BFS(2);
    g.BFS_disconnected_graph(); // this is for diconnceted graphs...
}
