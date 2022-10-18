/**
 * @file golombseq.cpp
 * @brief Golomb sequence (https://en.wikipedia.org/wiki/Golomb_sequence)
 * 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ...
 * where an is the number of times that n occurs in the sequence, starting with a1 = 1
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> a(n + 1, 0);
    a[1] = 1;

    // a(n) = 1 + a(n - a(a(n - 1)))
    for (int i = 2; i <= n; i++) {
        a[i] = 1 + a[i - a[a[i - 1]]];
    }

    for(auto i : a) cout << i << " ";
    cout << endl;

    return 0;
}

// Output
// Enter n: 11
// 0 1 2 2 3 3 4 4 4 5 5 5