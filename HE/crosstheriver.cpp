// https://www.hackerearth.com/problem/algorithm/cross-the-river-052be366/?source=list_view

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int x[n], y[n], r[n], dist[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }

        int A, B;
        cin >> A >> B;

        // adjacency matrix
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                long long d1 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                long long d2 = (r[i] + r[j]) * (r[i] + r[j]);
                if (d1 <= d2) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // check if any stone is touching the shore
        bool touching_A[n];
        bool touching_B[n];
        bool visited[n];

        for (int i = 0; i < n; i++) {
            touching_A[i] = false;
            touching_B[i] = false;
            visited[i] = false;
        }

        for (int i = 0; i < n; i++) {
            if (abs(y[i]-A) <= r[i]) {
                touching_A[i] = true;
            }
            if (abs(y[i]-B) <= r[i]) {
                touching_B[i] = true;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // init dist to int max
        for (int i = 0; i < n; i++) {
            dist[i] = numeric_limits<int>::max();
        }

        for (int i = 0; i < n; i++) {
            if (touching_B[i]) {
                dist[i] = 1;
                q.push(make_pair(1, i));
            }
        }

        int ans = numeric_limits<int>::max();
        while (!q.empty()) {
            int cost = q.top().first;
            int id = q.top().second;
            q.pop();
            if (visited[id]) {
                continue;
            }
            visited[id] = true;
            if (touching_A[id]) {
                ans = min(ans, cost);
            }
            for (int v : adj[id]) {
                if (dist[v] > cost + 1) {
                    dist[v] = cost + 1;
                    q.push(make_pair(cost + 1, v));
                }
            }
        }

        if (ans == numeric_limits<int>::max()) {
            cout << "-1" << endl;
        } else {
            cout << ans << endl;
        }

    }

    return 0;
}