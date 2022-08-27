// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/the-parking-slot-9fac40d6/
// https://www.youtube.com/watch?v=EFg3u_E6eHU

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

class Comparator {
public:
    bool operator()(const pair<int, long int>& p1, const pair<int, long int>& p2) {
        return p1.second > p2.second;
    }
};

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
    long int total_capacity = 0;

    for (int i = 0; i < n; i++) {
        cin >> capcity[i];
        total_capacity += capcity[i];
    }

    // adjacency list
    vector<pair<int, long int> > adj[n];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back(make_pair(v-1, w));
        adj[v-1].push_back(make_pair(u-1, w));
    }

    int cars;
    cin >> cars;

    long int dist[n];
    int path[n];
    bool visited[n];
    int curr_capcity[n];
    long int cost[cars];

    for (int i = 0; i < n; i++) {
        dist[i] = numeric_limits<long int>::max();  // this line is important
        visited[i] = false;
        curr_capcity[i] = 0;
    }

    for (int i = 0; i < cars; i++) {
        cost[i] = -1;
    }

    dist[0] = 0;
    path[0] = -1;

    int curr_car = 0;

    priority_queue<pair<int, long int>, vector<pair<int, long int> >, Comparator> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty() && curr_car < total_capacity) {

        int min_index = pq.top().first;
        long int min_dist = pq.top().second;

        // cout << "min_index: " << min_index << " min_dist: " << min_dist << endl;

        if (curr_capcity[min_index] < capcity[min_index]) {
            curr_capcity[min_index]++;
            cost[curr_car] = min_dist + f;
            curr_car++;
            if (curr_car == cars) {
                break;
            }
            continue;
        }

        pq.pop();
        visited[min_index] = true;

        // update the distance of all the neighbours of the min_index
        for (int i = 0; i < adj[min_index].size(); i++) {
            int v = adj[min_index][i].first;
            int w = adj[min_index][i].second;
            if (!visited[v] && dist[v] > dist[min_index] + w) {
                dist[v] = dist[min_index] + w;
                path[v] = min_index;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

    for (int i = 0; i < cars; i++) {
        cout << cost[i] << " ";
    }
    cout << endl;
    // for (int i = curr_car; i < cars; i++)
    // {
    //     cout << "-1" << " ";
    // }

    // for (int i = 0; i < n; i++) {
    //     cout << curr_capcity[i] << " " << capcity[i] << endl;
    // }


    return 0;
}