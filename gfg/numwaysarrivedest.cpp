#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int numWaysDest(vector<vector<int>> &roads, int n) {
    int src = 0, dest = n-1;

    // adjacency list
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    for (auto &road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;

    // number of ways to reach a node
    vector<int> ways(n, 0);
    ways[src] = 1;

    bool visited[n];
    memset(visited, false, sizeof(visited));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int u = curr.second;

        if (visited[u]) continue;

        visited[u] = true;

        // if destination is reached
        if (u == dest) break;

        for (auto &v : adj[u]) {
            if (visited[v.first]) continue;

            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
                ways[v.first] = ways[u];
            } else if (dist[u] + v.second == dist[v.first]) {
                ways[v.first] += ways[u];
            }
            // modulo
            ways[v.first] %= 1000000007;
        }
    }

    return ways[dest];
}

int main() {

    int n = 7, m = 10;
    vector<vector<int>> roads(m, vector<int>(3, 0));

    roads[0] = {0, 6, 7};
    roads[1] = {0, 1, 2};
    roads[2] = {1, 2, 3};
    roads[3] = {1, 3, 3};
    roads[4] = {6, 3, 3};
    roads[5] = {3, 5, 1};
    roads[6] = {6, 5, 1};
    roads[7] = {2, 5, 1};
    roads[8] = {0, 4, 5};
    roads[9] = {4, 6, 2};

    cout << numWaysDest(roads, n) << endl;

    return 0;
}