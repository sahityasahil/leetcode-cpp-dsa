class Solution {
public:
int m, n;
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == true || grid[r][c] == 0){
            return 0;
        }
        visited[r][c] = true;
        return 1 + (dfs(r+1, c, grid, visited)+dfs(r, c+1, grid, visited)+dfs(r-1, c, grid, visited)+dfs(r, c-1, grid, visited));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; i++){
            for (int j = 0; j <n; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    int curr_area = dfs(i, j, grid, visited);
                    res = max(res, curr_area);
                } 
            }
        }
        return res;
    }
};