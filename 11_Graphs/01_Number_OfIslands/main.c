#include <stdio.h>

void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    // Base case: check for bounds and if the cell is water ('0')
    if (r < 0 || c < 0 || r >= gridSize || c >= gridColSize[r] || grid[r][c] == '0')
        return;

    // Mark the cell as visited by setting it to '0'
    grid[r][c] = '0';

    // Explore all 4 directions: up, down, left, right
    dfs(grid, gridSize, gridColSize, r + 1, c);  // down
    dfs(grid, gridSize, gridColSize, r - 1, c);  // up
    dfs(grid, gridSize, gridColSize, r, c + 1);  // right
    dfs(grid, gridSize, gridColSize, r, c - 1);  // left
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int num_islands = 0;

    // Traverse each cell in the grid
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridColSize[r]; c++) {
            if (grid[r][c] == '1') {  // Found an island
                num_islands++;
                dfs(grid, gridSize, gridColSize, r, c);  // Mark all the land in this island
            }
        }
    }

    return num_islands;
}

int main() {
    // Example grid
    char* grid[] = {
        "11110",
        "11010",
        "11000",
        "00000"
    };
    int gridSize = 4;
    int gridColSize[] = {5, 5, 5, 5};

    int result = numIslands(grid, gridSize, gridColSize);
    printf("Number of islands: %d\n", result);  // Output: 1

    return 0;
}
