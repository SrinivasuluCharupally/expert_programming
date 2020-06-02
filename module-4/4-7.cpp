// Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first project). All of a project's dependencies must be built before the project is. Find a build order that will allow the projects to be built. If there is no valid build order, return an error.

// EXAMPLE
//	Input:
//	projects: a, b, c, d, e, f
//	dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
//	Output: f, e, a, b, d, c

#include<iostream>
#include<list>
#include<queue>
#include<stack>

using namespace std;

class Graph {
	int noOfNodes;
	list<int> *adj;
	
        bool *isBuilt;
        queue<int> buildOrderqueue;


  public:
	Graph(int n) {
		isBuilt = new bool [noOfNodes+1];
		for(int i =0; i <= noOfNodes; ++i) isBuilt[i] = false;

		noOfNodes = n;
		adj = new list<int> [n+1];
	}

	void addEdge(int s, int d) {
		adj[s].push_back(d);
	}


	void displayGraph() {
		
		for(int i = 1; i <= noOfNodes; ++i) {
			list<int> tmp = adj[i];
			while(!tmp.empty()) {
				cout << tmp.front();
				tmp.pop_front();
			}
			cout << endl;
		}
	}
/*
bool	 buildOrder() {
		bool checked[noOfNodes+1];
		for(int i = 0; i<= noOfNodes; ++i) checked[i] = false;

		queue<int> buildorderqueue;
		buildorderqueue.push(5);
		while(!buildorderqueue.empty()) {
			int s = buildorderqueue.front();
			buildorderqueue.pop();
			for(list<int>::iterator itr = adj[s].begin(); itr != adj[s].end(); ++itr)			 {
				if( *itr == 3) {
			                cout << " linke found " << endl;
					return true;
				}
				if(!checked[*itr]) {
					buildorderqueue.push(*itr);
					checked[*itr] = false;
				}
			}
		}
}

*/
void buildOrderLoop() {
	for(int i = 1; i <= noOfNodes; ++i) {
		if(!isBuilt[i]) {
		buildOrder(i); }
	}
}
bool buildOrder(int Node) {
		stack<int> tmpstack;
		tmpstack.push(Node);
		while(!tmpstack.empty()) { 
		int s = tmpstack.top();
                       if(adj[s].empty()) {
                                        if(!isBuilt[s]) {
                                                buildOrderqueue.push(s);
                                                isBuilt[s] = true;
						tmpstack.pop();
						
                                        }
                       }

			else {
				while(!adj[s].empty()) {
					if(!isBuilt[adj[s].front()]) {
					tmpstack.push(adj[s].front()); }
					adj[s].pop_front();
				
                        	}
			}

		}
}



void displayOrder() {
	while(!buildOrderqueue.empty()) {
			cout << buildOrderqueue.front() << " ";
			buildOrderqueue.pop();
		}
		cout << endl;
}


};





int main() {
        Graph rt(6);
        rt.addEdge(1,4);
        rt.addEdge(6,2);
        rt.addEdge(2,4);
        rt.addEdge(6,1);
        rt.addEdge(4,3);
//        rt.addEdge(3,3);
//        rt.addEdge()
rt.displayGraph();
rt.buildOrderLoop();
rt.displayOrder();
/*        cout << "Finding route b/w 0, 3 " ;
        if(!rt.isReachable(0,3)) {
                cout << " Path Not found" << endl;
        }
        else cout << " Path found" << endl;

        cout << "Finding route b/w 1, 3 " ;
        if(!rt.isReachable(1,3)) {
                cout << " Path Not found" << endl;
        }
        else cout << " Path found" << endl;

*/
}

