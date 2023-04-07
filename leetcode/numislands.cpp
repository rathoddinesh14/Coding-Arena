#include <iostream>
#include <vector>

using namespace std;

void FloodFill(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    FloodFill(grid, i - 1, j);
    FloodFill(grid, i + 1, j);
    FloodFill(grid, i, j - 1);
    FloodFill(grid, i, j + 1);
}

/**
 * @brief number of islands
 * Time Complexity: O(MN)
 * 
 * @param grid 
 * @return int - number of islands
 */
int numIslands(vector<vector<char>>& grid) {

    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                count++;
                FloodFill(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << numIslands(grid) << endl;

    return 0;
}