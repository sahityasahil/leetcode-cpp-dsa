class Solution {
public:
    int row, col;
    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        // Check if out of bounds or water cell
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0) {
            return 1; // Contribute 1 to perimeter for boundary or water
        }
        // Skip if already visited
        if (visited[r][c]) {
            return 0;
        }
        
        visited[r][c] = true; // Mark as visited
        
        // Sum perimeter contributions from all four directions
        return (dfs(r + 1, c, grid, visited) +
                dfs(r - 1, c, grid, visited) +
                dfs(r, c + 1, grid, visited) +
                dfs(r, c - 1, grid, visited));
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        // Find the first land cell and start DFS
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid, visited); // Single DFS call for the island
                }
            }
        }
        
        return 0; // Should not reach here given problem constraints
    }
};