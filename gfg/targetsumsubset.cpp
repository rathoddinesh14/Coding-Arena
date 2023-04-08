#include <iostream>
#include <vector>
using namespace std;


/**
 * @brief Given an array of integers and a target sum, 
 * find if there is a subset of the given set with sum equal to the given target sum.
 * Time Complexity: O(n * sum)
 * @param arr 
 * @param sum 
 * @return true 
 * @return false 
 */
bool isTargetSumSubsetPossible(vector<int> &arr, int sum) {

    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base case - if sum is 0, then there is only one subset possible i.e. empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Base case - if n is 0, then there is no subset possible
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = 60;

    cout << "Target sum subset: " << isTargetSumSubsetPossible(arr, sum) << endl;

    return 0;
}