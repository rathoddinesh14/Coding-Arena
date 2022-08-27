// pq gives constant time lookup for min/max element

#include <iostream>
#include <queue>

using namespace std;




class Comparator {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

int main() {

    priority_queue<pair<int, int>, vector<pair<int, int> >, Comparator> pq; 

    int n = 10;

    for (int i = 0; i < n; i++) {
        pq.push(make_pair(i, i));
    }

    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}