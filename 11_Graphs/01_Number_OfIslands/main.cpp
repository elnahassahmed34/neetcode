#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Boundary check and if the current cell is water ('0'), return
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';
        
        // Perform DFS in all 4 possible directions (up, down, left, right)
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int num_islands = 0;
        
        // Traverse each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is land ('1'), it's the start of a new island
                if (grid[i][j] == '1') {
                    num_islands++;
                    // Perform DFS to mark the entire island as visited
                    dfs(grid, i, j);
                }
            }
        }
        
        return num_islands;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    int result1 = solution.numIslands(grid1);
    int result2 = solution.numIslands(grid2);
    
    printf("Number of islands in grid1: %d\n", result1); // Output: 1
    printf("Number of islands in grid2: %d\n", result2); // Output: 3
    
    return 0;
}
