// https://www.geeksforgeeks.org/topological-sorting/


#include <iostream>
#include <list>
#include <stack>

using namespace std;


/**
 * @brief Topological sort of a directed acyclic graph (DAG)
 * Time complexity: O(V + E)
 * DFS is used to find the topological sort
 */

class Graph {
	int V;
	list<int> *adj;

	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V);

	void addEdge(int v, int w);

	void topologicalSort();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack) {
	
    // Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {

        if (!visited[*i]) {
            topologicalSortUtil(*i, visited, Stack);
        }

    }

	// Push current vertex to stack which stores result
	Stack.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort() {
	
    // stack to store the topological sorted elements
    stack<int> Stack;

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) visited[i] = false;

	for (int i = 0; i < V; i++) {

        if (visited[i] == false) topologicalSortUtil(i, visited, Stack);
    
    }

	// Print contents of stack
	while (Stack.empty() == false) {

		cout << Stack.top() << " ";
		Stack.pop();

	}

    cout << endl;
}


int main() {

	Graph g(6);     // Topological sort of a DAG - 5, 4, 2, 3, 1, 0
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph \n";

	g.topologicalSort();
	return 0;
}
