// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/


/**
 * @file cycledfs.cpp
 * @brief Detect cycle in an undirected graph using DFS
 * Time Complexity: O(V+E)
 * Space Complexity: O(V) - for visited array
 */


#include <iostream>
#include <limits.h>
#include <list>


using namespace std;


class Graph {

	int V;
	list<int>* adj;

	bool isCyclicUtil(int v, bool visited[], int parent);

public:
	Graph(int V);

	void addEdge(int v, int w);

	// Returns true if there is a cycle
	bool isCyclic();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent) {

	visited[v] = true;

	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); ++i) {

		// If an adjacent vertex is not visited,
		// then recur for that adjacent
		if (!visited[*i]) {
			if (isCyclicUtil(*i, visited, v))
				return true;
		}

		// If an adjacent vertex is visited and
		// is not parent of current vertex,
		// then there exists a cycle in the graph.
        // *i == parent means that bi-directional edge which is not a cycle
		else if (*i != parent)
			return true;
	}
	return false;
}


bool Graph::isCyclic() {

	bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int u = 0; u < V; u++) {

		// Don't recur for u if
		// it is already visited
		if (!visited[u])
			if (isCyclicUtil(u, visited, -1))
				return true;
	}
	return false;
}


int main() {

	Graph g1(5);    // contains cycle
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	Graph g2(3);    // doesn't contain cycle
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	return 0;
}
