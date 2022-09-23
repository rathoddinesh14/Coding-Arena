// https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/
// check if there is a cycle in directed graph using BFS.


#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

// variant of kahn's algorithm.
// here, we try to construct a topological sort.
// if we are not able to construct a topological sort, then there is a cycle
// Time complexity: O(V+E)

class Graph {
	int V;
	list<int>* adj;

public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isCycle(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
}


bool Graph::isCycle() {
	// Initialize all indegrees as 0.
	vector<int> in_degree(V, 0);

	// Traverse adjacency lists to fill indegrees of
	// vertices. This step takes O(V+E) time
	for (int u = 0; u < V; u++) {
		for (auto v : adj[u])
			in_degree[v]++;
	}

	// Create an queue and enqueue all vertices with
	// indegree 0
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	// Initialize count of visited vertices
	// 1 For src Node
	int cnt = 1;

	// A topological ordering of the vertices
	vector<int> top_order;

	// One by one dequeue vertices from queue and enqueue
	// adjacents if indegree of adjacent becomes 0
	while (!q.empty()) {

		// Extract front of queue (or perform dequeue)
		// and add it to topological order
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// Iterate through all its neighbouring nodes
		// of dequeued node u and decrease their in-degree
		// by 1
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            // If in-degree becomes zero, add it to queue
			if (--in_degree[*itr] == 0) {
                q.push(*itr);
                cnt++;
			}
        }
	}

	// Check if there was a cycle
	if (cnt != V) return true;
	else return false;
}


int main() {

	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	if (g.isCycle()) cout << "Yes";
	else cout << "No";
    cout << endl;

	return 0;
}
