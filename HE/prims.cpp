// https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/


/**
 * @file prims.cpp
 * @brief Prims algorithm using priority_queue stl
 * Time Complexity: O(ElogV)
 * @version 0.1
 * @date 2022-09-28
 * 
 */

#include <iostream>
#include <list>
#include <queue>
#include <limits>

using namespace std;


typedef pair<int, int> iPair;


class Graph {
	int V;
	list< pair<int, int> > *adj;

public:
	Graph(int V);

	void addEdge(int u, int v, int w);

	void primMST();
};


Graph::Graph(int V) {
	this->V = V;
	adj = new list<iPair> [V];
}


void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}


void Graph::primMST() {

	// priority queue to store vertices that are being prims MST.
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src = 0; // Taking vertex 0 as source

	vector<int> dist(V, numeric_limits<int>::max());

	// To store parent array which in turn store MST
	vector<int> parent(V, -1);

	// To keep track of vertices included in MST
	vector<bool> inMST(V, false);

    dist[src] = 0;
	// Insert source itself in priority queue and initialize
	// its dist as 0.
	pq.push(make_pair(dist[src], src));

	while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // second vertex in pair is the vertex number
		int u = pq.top().second;
		pq.pop();
		
		//Different distances values for same vertex may exist in the priority queue.
		//The one with the least distance value is always processed first.
		//Therefore, ignore the rest.
		if(inMST[u] == true){
			continue;
		}
	
		inMST[u] = true; // Include vertex in MST

		list< iPair >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {

			// Get vertex label and weight of current adjacent
			// of u.

			int v = (*i).first;
			int weight = (*i).second;

			// If v is not in MST and weight of (u,v) is smaller
			// than current distance of v
			if (inMST[v] == false && dist[v] > weight) {

				// Updating key of v
				dist[v] = weight;
				pq.push(make_pair(dist[v], v));
				parent[v] = u;
			}
		}
	}

	// Print edges of MST using parent array
	for (int i = 0; i < V; ++i)
		printf("%d - %d\n", parent[i], i);
}


int main() {

	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.primMST();

    /*
    Output - 
           -1 - 0
            0 - 1
            1 - 2
            2 - 3
            3 - 4
            2 - 5
            5 - 6
            6 - 7
            2 - 8
    */ 

	return 0;
}
