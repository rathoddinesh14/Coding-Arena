#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/**
 * @brief Depth First Search
 * Time Complexity: O(V + E)
 * 
 * @param adjMatrix 
 * @param isVisited 
 * @param i 
 */
void dfs(vector<vector<int>>& adjMatrix, bool isVisited[], int i) {
    isVisited[i] = true;
    for (int j = 0; j < adjMatrix[i].size(); j++) {
        if (adjMatrix[i][j] == 1 && !isVisited[j]) {
            dfs(adjMatrix, isVisited, j);
        }
    }
}

/**
 * @brief Number of provinces in a graph
 * Time Complexity: O (V + E)
 * 
 * @param adjMatrix 
 * @return int 
 */
int numProvinces(vector<vector<int>>& adjMatrix) {
    bool isVisited[adjMatrix.size()];
    memset(isVisited, false, sizeof(isVisited));

    int numProvinces = 0;
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (!isVisited[i]) {
            numProvinces++;
            dfs(adjMatrix, isVisited, i);
        }
    }

    return numProvinces;
}

int main() {

    vector<vector<int>> provinces = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << "Number of provinces: " << numProvinces(provinces) << endl;

    return 0;
}