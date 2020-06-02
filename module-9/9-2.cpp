//Social Network: How would you design the data structures for a very large social network like Facebook or Linkedln? Describe how you would design an algorithm to show the shortest path between two people (e.g., Me-> Bob-> Susan-> Jason-> You).

// i didnt use machine ID, but that can be done easily ...http://xiaochongzhang.me/blog/?p=848
 
// Route between nodes
// source http://www.sanfoundry.com/cpp-program-find-whether-path-exists-between-2-given-nodes/

#include<iostream>
#include<list>

using namespace std;


class RouteBtNodes {
	int totalNodes;
	list<int> *adj;
	list<int>* path;
  public:
	RouteBtNodes(int nodes) { 
		totalNodes = nodes;
		adj = new list<int> [nodes];
	}

	void addEdge(int n, int a);
	bool isReachable(int s, int d);
	void printpath(int source, int d);
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
	int source = s;
	path = new list<int> [tatalNodes]
	vTracker[s] = true;
	list<int>::iterator itr;
	int i = 0;
	while(!tmpqueue.empty()) {
		s = tmpqueue.front();
		tmpqueue.pop_front();
		for(itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
			if(*itr == d) {
                              path[i].push_back(*itr);
				printpath(source, d);
				return true;
			}
			if(!vTracker[*itr]) {
//				path[i].push_back(*itr);
				vTracker[*itr] = true;
				tmpqueue.push_back(*itr);
//				i++;
			}
                        path[i].push_back(*itr); ++i;

		}
		i=0;
	}
	return false;
}

void RouteBtNodes::printpath(int source, int dest) {
	for(int i = 0; i<adj[source].size(); ++i) {
		if(path[i].back() == dest) {
                cout << "path : " << source ;
		for(list<int>::iterator itr = path[i].begin(); itr != path[i].end(); ++itr) {
		cout << "->" <<  *itr ;
		}
		cout <<  endl;
		}
	}
}
int main() {
	RouteBtNodes rt(4);
	rt.addEdge(0,1);		
        rt.addEdge(0,2);
        rt.addEdge(1,2);
//        rt.addEdge(2,0);
        rt.addEdge(2,3);
//        rt.addEdge(3,3);
//        rt.addEdge()

	cout << "Finding route b/w 0, 3 " << endl;
	if(!rt.isReachable(0,3)) {
		cout << " Path Not found" << endl;
	}
	
	else cout << " Path found" << endl << endl;

        cout << "Finding route b/w 1, 3 " << endl;
        if(!rt.isReachable(1,3)) {
                cout << " Path Not found" << endl;
        }
        else cout << " Path found" << endl << endl;


}

