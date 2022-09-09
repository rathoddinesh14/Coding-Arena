// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// recursive approach
int lcs( char *X, char *Y, int m, int n ) {
	
    // base case
    if (m == 0 || n == 0) return 0;
	
    // if last characters of X and Y are same
    if (X[m-1] == Y[n-1]) return 1 + lcs(X, Y, m-1, n-1);

	else return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

// recursive approach with memoization
// Time Complexity : O(mn) ignoring recursion stack space
int lcs(char* X, char* Y, int m, int n, vector<vector<int> >& dp) {
    
    // base case
    if (m == 0 || n == 0) return 0;
    
    // if last characters are same
    if (X[m - 1] == Y[n - 1]) return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
 
    // if this subproblem is already solved
    if (dp[m][n] != -1) return dp[m][n];
    
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}

// tabulation approach
// Time Complexity : O(mn)
int lcs_t(char *X, char *Y, int m, int n) {

    // intitalizing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
 

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0) L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
 
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int main() {
	
    char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) << endl;

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));

    cout << "Length of LCS is " << lcs(X, Y, m, n, dp) << endl;

    cout << "Length of LCS is " << lcs_t(X, Y, m, n) << endl;
	
	return 0;
}