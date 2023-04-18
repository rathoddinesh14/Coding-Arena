#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Counting Bits
 * Time Complexity: O(n)
 * 
 * @param n 
 * @return vector<int> 
 */
vector<int> countBits(int n) {
    vector<int> result(n+1, 0);
    for(int i = 1; i <= n; i++) {
        result[i] = result[i & (i-1)] + 1;
    }
    return result;
}

int main() {

    // output: 0 1 1 2 1 2
    for(auto i : countBits(5))
        cout << i << " ";
    cout << endl;

    return 0;
}