// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/


/**
 * @brief A graph can have multiple spanning trees.
 * N vertices and N-1 edges.
 * Note : Greedy algorithm.
 * Kruskal's algorithm to find Minimum
 * Spanning Tree of a given connected, undirected and
 * weighted graph
 * Time Complexity: O(ElogE) or O(ElogV).
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// shortcut - integer pair
typedef pair<int, int> iPair;


struct Graph {
	int V, E;
	vector< pair<int, iPair> > edges;


	Graph(int V, int E)	{
		this->V = V;
		this->E = E;
	}


	void addEdge(int u, int v, int w) {
		edges.push_back(make_pair<int, iPair>(w, make_pair<int, int>(u, v)));
	}

	int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets {
	int *parent, *rnk;
	int n;

	DisjointSets(int n) {

		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++) {
			rnk[i] = 0;
			parent[i] = i;	//every element is parent of itself
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u) {
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y) {

		x = find(x), y = find(y);

		/* Make tree with smaller height
		a subtree of the other tree */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else 
			// If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y]) rnk[y]++;
	}
};

/**
 * @brief kruskalMST() - main function to construct MST using Kruskal's algorithm
 * 
 * @return int - weight of MST
 */
int Graph::kruskalMST() {

	int mst_wt = 0; // Initialize result

	// Sort edges in increasing order on basis of cost
	// Time Complexity: O(ElogE)
	sort(edges.begin(), edges.end());

	// Create disjoint sets
	DisjointSets ds(V);

	// Iterate through all sorted edges
	vector< pair<int, iPair> >::iterator it;
	for (it = edges.begin(); it != edges.end(); it++) {

		// it->first is the weight of current edge
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);	// O(logV)
		int set_v = ds.find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v) {
			// Current edge will be in the MST
			// so print it
			cout << u << " - " << v << endl;

			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}


int main() {

	int V = 9, E = 14;
	Graph g(V, E);

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

	cout << "Edges of MST are \n";
	int mst_wt = g.kruskalMST();

	cout << "\nWeight of MST is " << mst_wt << endl;

	/* - output -
					Edges of MST are 
					6 - 7
					2 - 8
					5 - 6
					0 - 1
					2 - 5
					2 - 3
					0 - 7
					3 - 4

					Weight of MST is 37
	*/

	return 0;
}
