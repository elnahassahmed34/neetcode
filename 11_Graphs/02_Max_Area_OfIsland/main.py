class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        max_area = 0
        
        def dfs(r, c):
            # Base case: check for bounds and if the cell is water (0)
            if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] == 0:
                return 0
            
            # Mark the cell as visited by setting it to 0
            grid[r][c] = 0
            
            # Calculate area: 1 for the current cell + area from all 4 directions
            area = 1
            area += dfs(r + 1, c)  # down
            area += dfs(r - 1, c)  # up
            area += dfs(r, c + 1)  # right
            area += dfs(r, c - 1)  # left
            
            return area
        
        # Traverse each cell in the grid
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:  # Found an island
                    max_area = max(max_area, dfs(r, c))
        
        return max_area
