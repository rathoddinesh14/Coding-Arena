#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Find the maximum sum of non adjacent subarray
 * Time Complexity: O(2^n) - This is because we are making two recursive calls for each element
 * 
 * @param arr 
 * @param i 
 * @return int 
 */
int maxSumNonAdjSubarrayRecursive(vector<int> &arr, int i) {
    if (i < 0) return 0;

    if (i == 0) return arr[0];
    else {
        return max(maxSumNonAdjSubarrayRecursive(arr, i - 1), maxSumNonAdjSubarrayRecursive(arr, i - 2) + arr[i]);
    }
}

/**
 * @brief Find the maximum sum of non adjacent subarray
 * Time Complexity: O(n)
 * 
 * @param arr 
 * @return int 
 */
int maxSumNonAdjSubarrayDP(vector<int> &arr) {
    vector<pair<int, int>> dp(arr.size());
    dp[0] = {arr[0], 0};    // {max sum including current element, max sum excluding current element}

    for (int i = 1; i < arr.size(); i++) {
        dp[i].first = dp[i - 1].second + arr[i];
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }

    return max(dp[arr.size() - 1].first, dp[arr.size() - 1].second);
}

/**
 * @brief Find the maximum sum of non adjacent subarray
 * Time Complexity: O(n)
 * 
 * @param arr 
 * @return int 
 */
int maxSumNonAdjSubarray(vector<int> &arr) {
    int incl = arr[0];
    int excl = 0;
    int excl_new;

    for (int i = 1; i < arr.size(); i++) {
        excl_new = max(incl, excl);
        incl = excl + arr[i];
        excl = excl_new;
    }

    return max(incl, excl);
}

int main() {

    // vector<int> arr = {2, 1, 4, 9};
    vector<int> arr = {5, 5, 10, 100, 10, 5};

    cout << "(Recursive) Max sum of non adjacent subarray is: " << maxSumNonAdjSubarrayRecursive(arr, arr.size() - 1) << endl;
    cout << "(DP) Max sum of non adjacent subarray is: " << maxSumNonAdjSubarrayDP(arr) << endl;
    cout << "(Iterative) Max sum of non adjacent subarray is: " << maxSumNonAdjSubarray(arr) << endl;

    return 0;
}