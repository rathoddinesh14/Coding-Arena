// source: https://www.hackerearth.com/problem/algorithm/alternative-moves-f12ee40a/?source=list_view

#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    int a, b, n, x;
    while(t--) {
        cin >> n >> a >> b;

        // cout << s1 << " " << s2 << endl;

        // check which is integer
		if (n <= a) {
            cout << "1" << endl;
        }
        else if (a < b) {
            cout << "-1" << endl;
        }
        else {
            cout << 1 + 2*((n-b-1)/(a-b)) << endl;
        }
    }

    return 0;
}