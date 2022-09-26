// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// https://www.youtube.com/watch?v=rZv_jHZva34


#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief Kahn's algorithm for topological sort.
 * Uses BFS to find the topological sort.
 */

class Graph {
	int V;
	list<int>* adj;

public:
	Graph(int V);

	void addEdge(int u, int v);

	void topologicalSort();
};


Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}


void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
}


void Graph::topologicalSort()
{
	vector<int> in_degree(V, 0);

	// Traverse adjacency lists to fill indegrees of vertices (V+E)
	for (int u = 0; u < V; u++) {
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}

	// enqueue (indegree : 0)
    // Invariant: all vertices in the queue have indegree 0
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0) q.push(i);

	// Initialize count of visited vertices
	int cnt = 0;

	// topological ordering
	vector<int> top_order;

	while (!q.empty()) {
		// Extract front of queue
		// and add it to topological order
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// decrease their in-degree by 1
		list<int>::iterator itr;
		for (itr = adj[u].begin();
			itr != adj[u].end(); itr++)

			// If in-degree becomes zero,
			// add it to queue
			if (--in_degree[*itr] == 0)
				q.push(*itr);

		cnt++;
	}

	// Check if there was a cycle
	if (cnt != V) {
		cout << "There exists a cycle in the graph\n";
		return;
	}

	// Print topological order
	for (int i = 0; i < top_order.size(); i++)
		cout << top_order[i] << " ";
	cout << endl;
}


int main() {

	Graph g(6);     // Topo sort : 4 5 2 0 3 1
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of\n";
	g.topologicalSort();

	return 0;
}
