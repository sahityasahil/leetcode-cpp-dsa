class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int m, int n) {
        
        if (row < 0 || col < 0 || row >= m || col >= n || 
            vis[row][col] == 1 || grid[row][col] == '0') {
            return;
        }
        
        vis[row][col] = 1;

        dfs(row+1, col, grid, vis, m, n);
        dfs(row-1, col, grid, vis, m, n);
        dfs(row, col+1, grid, vis, m, n);
        dfs(row, col-1, grid, vis, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j, grid, vis, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};
