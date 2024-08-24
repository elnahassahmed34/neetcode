class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        num_islands = 0
        rows, cols = len(grid), len(grid[0])
        
        def dfs(r, c):
            # Base case: check for bounds and if the cell is water ('0')
            if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] == '0':
                return
            
            # Mark the cell as visited by setting it to '0'
            grid[r][c] = '0'
            
            # Explore all 4 directions: up, down, left, right
            dfs(r + 1, c)  # down
            dfs(r - 1, c)  # up
            dfs(r, c + 1)  # right
            dfs(r, c - 1)  # left
        
        # Traverse each cell in the grid
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':  # Found an island
                    num_islands += 1
                    dfs(r, c)  # Mark all the land in this island
        
        return num_islands
