#include <stdio.h>

int dfs(int** grid, int gridSize, int* gridColSize, int r, int c) {
    // Base case: check for bounds and if the cell is water (0)
    if (r < 0 || c < 0 || r >= gridSize || c >= gridColSize[r] || grid[r][c] == 0)
        return 0;

    // Mark the cell as visited by setting it to 0
    grid[r][c] = 0;

    // Calculate area: 1 for the current cell + area from all 4 directions
    int area = 1;
    area += dfs(grid, gridSize, gridColSize, r + 1, c);  // down
    area += dfs(grid, gridSize, gridColSize, r - 1, c);  // up
    area += dfs(grid, gridSize, gridColSize, r, c + 1);  // right
    area += dfs(grid, gridSize, gridColSize, r, c - 1);  // left

    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int max_area = 0;

    // Traverse each cell in the grid
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridColSize[r]; c++) {
            if (grid[r][c] == 1) {  // Found an island
                int area = dfs(grid, gridSize, gridColSize, r, c);
                if (area > max_area)
                    max_area = area;
            }
        }
    }

    return max_area;
}

int main() {
    // Example grid
    int grid[][5] = {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,1,1,0,0},
        {0,1,0,0,1},
        {0,1,0,0,1},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {0,0,1,0,0}
    };
    int gridSize = 8;
    int gridColSize[] = {5, 5, 5, 5, 5, 5, 5, 5};

    int* gridPtrs[8];
    for (int i = 0; i < gridSize; i++) {
        gridPtrs[i] = grid[i];
    }

    int result = maxAreaOfIsland(gridPtrs, gridSize, gridColSize);
    printf("Maximum area of an island: %d\n", result);  // Output: 4

    return 0;
}
