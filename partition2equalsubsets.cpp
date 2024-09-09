#include <iostream>
#include <vector>

using namespace std;

bool partitionUntil(int n, vector<int>& arr, int target, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (n == 0) return (arr[0] == target);
    if (dp[n][target] != -1) return dp[n][target];
     bool notTaken = partitionUntil(n-1, arr, target, dp);
     bool taken = false;
     if (arr[n] <= target) {
         taken = partitionUntil(n-1, arr, target - arr[n], dp);
     }
     return dp[n][target] = (notTaken || taken);
}

bool validPartitionOp(int n, vector<int> &arr) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0)
        return false;

    int targetSum = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(targetSum+1, -1));
    return partitionUntil(n-1, arr, targetSum, dp);
}

bool validPartitionTabulation(int n, vector<int> &arr) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0)
        return false;

    int targetSum = totalSum / 2;
    vector<vector<bool>> dp(n, vector<bool>(targetSum+1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if (arr[0] <= targetSum) {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            bool notTaken = dp[i-1][j];
            bool taken = false;
            if (arr[i] <= j) {
                taken = dp[i-1][j - arr[i]];
            }
            dp[i][j] = (notTaken || taken);
        }
    }
    return dp[n-1][targetSum];
}

// Time Complexity: O(n * targetSum)
// Space Complexity: O(targetSum

int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (validPartitionOp(n, arr))
        cout << "Given Array can be split into 2 eq subsets";
    else
        cout << "Given Array cannot be split into 2 eq subsets";

    return 0;
}