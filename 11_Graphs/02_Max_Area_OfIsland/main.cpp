#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Helper function to perform DFS and calculate the area of an island
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Check boundaries and if the current cell is water (0)
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return 0;

        // Mark the current cell as visited by setting it to 0
        grid[r][c] = 0;

        // Calculate the area of the island: 1 for the current cell + area from all 4 directions
        int area = 1;
        area += dfs(grid, r + 1, c);  // Down
        area += dfs(grid, r - 1, c);  // Up
        area += dfs(grid, r, c + 1);  // Right
        area += dfs(grid, r, c - 1);  // Left

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        // Traverse each cell in the grid
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                // If the current cell is land (1), calculate the island's area
                if (grid[r][c] == 1) {
                    max_area = max(max_area, dfs(grid, r, c));
                }
            }
        }

        return max_area;
    }
};

// Main function to test the solution
int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    Solution solution;
    int result = solution.maxAreaOfIsland(grid);
    cout << "Maximum area of an island: " << result << endl;  // Output: 6

    return 0;
}
