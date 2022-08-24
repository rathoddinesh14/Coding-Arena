// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/the-parking-slot-9fac40d6/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool all_visited(bool v[] , int n) {
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    int n, m, f;
    cin >> n >> m >> f;

    int capcity[n];

    for (int i = 0; i < n; i++) {
        cin >> capcity[i];
    }

    // adjacency list
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back(make_pair(v-1, w));
        adj[v-1].push_back(make_pair(u-1, w));
    }

    int cars;
    cin >> cars;

    int dist[n];
    int path[n];
    bool visited[n];
    int curr_capcity[n];
    int cost[n];

    for (int i = 0; i < n; i++) {
        dist[i] = numeric_limits<int>::max();
        visited[i] = false;
        curr_capcity[i] = 0;
        cost[i] = -1;
    }

    dist[0] = 0;
    path[0] = -1;

    int curr_car = 0;

    while (all_visited(visited, n) == false) {
        int min_dist = numeric_limits<int>::max();
        int min_index = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                min_index = i;
            }
        }
        
        if (curr_capcity[min_index] < capcity[min_index]) {
            curr_capcity[min_index]++;
            cost[curr_car] = min_dist + f;
            curr_car++;
            if (curr_car == cars) {
                break;
            }
            continue;
        }
        visited[min_index] = true;

        // update the distance of all the neighbours of the min_index
        for (int i = 0; i < adj[min_index].size(); i++) {
            int v = adj[min_index][i].first;
            int w = adj[min_index][i].second;
            if (dist[v] > dist[min_index] + w) {
                dist[v] = dist[min_index] + w;
                path[v] = min_index;
            }
        }
    }

    for (int i = 0; i < curr_car; i++) {
        cout << cost[i] << " ";
    }
    for (int i = curr_car; i < cars; i++)
    {
        cout << "-1" << " ";
    }

    return 0;
}