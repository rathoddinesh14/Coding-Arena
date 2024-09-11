#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, 0);
    
    for(int i = 1; i < n; i++) {
        int oneStep = dp[i-1] + abs(heights[i] - heights[i-1]);
        int twoStep = INT_MAX;
        if (i > 1) {
            twoStep = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(oneStep, twoStep);
    }

    return dp[n-1];
}

int main() {
    int n = 5;
    vector<int> heights = {30, 10, 60, 10, 60};
    cout << frogJump(n, heights) << endl;
}