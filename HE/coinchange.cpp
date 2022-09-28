// https://www.geeksforgeeks.org/coin-change-dp-7/



#include <iostream>

using namespace std;

/**
 * @brief recursive solution to coin change problem
 * Time Complexity: O(2 ^ sum)
 * @param coins 
 * @param n 
 * @param sum 
 * @return int 
 */
int count(int coins[], int n, int sum) {

	// If sum is 0 then there is 1 solution
	// (do not include any coin)
	if (sum == 0) return 1;

	// If sum is less than 0 then no
	// solution exists
	if (sum < 0) return 0;

	// If there are no coins and sum
	// is greater than 0, then no
	// solution exist
	if (n <= 0) return 0;

	// count is sum of solutions (i)
	// including coins[n-1] (ii) excluding coins[n-1]
	return count(coins, n - 1, sum) + count(coins, n, sum - coins[n - 1]);
}


/**
 * @brief DP solution to coin change problem
 * Time Complexity: O(sum * n)
 * @param coins
 * @param n
 * @param sum
 * @return int
 */
int countDP(int coins[], int n, int sum) {
    int i, j, x, y;

    // We need sum+1 rows as the table is constructed
    // in bottom up manner using the base case 0 value
    // case (sum = 0)
    int table[sum + 1][n];

    // Fill the enteries for 0 value case (n = 0)
    for (i = 0; i < n; i++)
        table[0][i] = 1;

    // Fill rest of the table enteries in bottom
    // up manner
    for (i = 1; i < sum + 1; i++) {
        for (j = 0; j < n; j++) {
            // Count of solutions including coins[j]
            x = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;

            // Count of solutions excluding coins[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[sum][n - 1];
}

/**
 * @brief 1D DP solution to coin change problem
 * Time Complexity: O(sum * n)
 * @param coins
 * @param n
 * @param sum
 * @return int
 */
int countDP1D(int coins[], int n, int sum) {

    // table[i] will be storing the number of solutions for
    // value i. We need sum+1 rows as the table is
    // constructed in bottom up manner using the base case
    // (sum = 0)
    int table[sum + 1];
 
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all coins one by one and update the table[]
    // values after the index greater than or equal to the
    // value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            table[j] += table[j - coins[i]];
    return table[sum];
}

int main() {
	int i, j;
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;

    // ans = 4

	cout << "Recusrive : " << count(coins, n, sum) << endl;
    cout << "DP : " << countDP(coins, n, sum) << endl;
    cout << "DP 1D : " << countDP1D(coins, n, sum) << endl;

	return 0;
}