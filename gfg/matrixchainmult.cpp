#include <iostream>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief Matrix Chain Multiplication
 * Time Complexity: O(2^n)
 * 
 * @param mat 
 * @param i 
 * @param j 
 * @return int
 */
int matrixChainMultSub(vector<int>& mat, int i, int j) {
    
    if (i == j) {
        return 0;
    }

    int minCost = numeric_limits<int>::max();
    for (int k = i; k < j; k++) {
        int cost = matrixChainMultSub(mat, i, k) + matrixChainMultSub(mat, k + 1, j) + mat[i-1] * mat[k] * mat[j];
        minCost = min(minCost, cost);
    }

    return minCost;
}

/**
 * @brief Matrix Chain Multiplication
 * Time Complexity: O(n^3)
 * 
 * @param mat 
 * @param i 
 * @param j 
 * @param memo 
 * @return int 
 */
int matrixChainMultSubMemoized(vector<int>& mat, int i, int j, vector<vector<int>>& memo) {
    
    if (i == j) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int minCost = numeric_limits<int>::max();
    
    for (int k = i; k < j; k++) {
        
        int cost =  matrixChainMultSubMemoized(mat, i, k, memo) + 
                    matrixChainMultSubMemoized(mat, k + 1, j, memo) + 
                    mat[i-1] * mat[k] * mat[j];
        
        minCost = min(minCost, cost);
    }

    memo[i][j] = minCost;
    return minCost;
}

// DP version of matrix chain multiplication
// TODO: Implement DP version of matrix chain multiplication


int matrixChainMult(vector<int>& mat) {
    vector<vector<int>> memo(mat.size(), vector<int>(mat.size(), -1));
    // return matrixChainMultSub(mat, 1, mat.size() - 1);
    return matrixChainMultSubMemoized(mat, 1, mat.size() - 1, memo);
}

int main() {

    vector<int> mat = {1, 2, 3, 4};

    cout << "Optimal cost: " << matrixChainMult(mat) << endl;
    // output: Optimal cost: 18
    return 0;
}