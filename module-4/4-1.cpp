// Route between nodes, : Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

//source http://www.sanfoundry.com/cpp-program-find-whether-path-exists-between-2-given-nodes/

#include<iostream>
#include<list>

using namespace std;


class RouteBtNodes {
	int totalNodes;
	list<int> *adj;

  public:
	RouteBtNodes(int nodes) { 
		totalNodes = nodes;
		adj = new list<int> [nodes];
	}

	void addEdge(int n, int a);
	bool isReachable(int s, int d);
};

void RouteBtNodes::addEdge(int n, int a) {
	adj[n].push_back(a);
}

bool RouteBtNodes::isReachable(int s, int d) {
	if(s == d) {
		return true;
	}

	bool* vTracker = new bool[totalNodes];
	for(int i =0; i < totalNodes; ++i) {
		vTracker[i] = false;
	}

	list<int> tmpqueue;
	tmpqueue.push_back(s);
	vTracker[s] = true;
	list<int>::iterator itr;
	while(!tmpqueue.empty()) {
		s = tmpqueue.front();
		tmpqueue.pop_front();
		for(itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
			if(*itr == d) {
				return true;
			}
			if(!vTracker[*itr]) {
				vTracker[*itr] = true;
				tmpqueue.push_back(*itr);
			}
		}
	} 
	return false;
}

int main() {
	RouteBtNodes rt(4);
	rt.addEdge(0,1);		
        rt.addEdge(0,2);
        rt.addEdge(1,2);
        rt.addEdge(2,0);
        rt.addEdge(2,3);
        rt.addEdge(3,3);
//        rt.addEdge()

	cout << "Finding route b/w 0, 3 " ;
	if(!rt.isReachable(0,3)) {
		cout << " Path Not found" << endl;
	}
	else cout << " Path found" << endl;

        cout << "Finding route b/w 1, 3 " ;
        if(!rt.isReachable(1,3)) {
                cout << " Path Not found" << endl;
        }
        else cout << " Path found" << endl;


}

