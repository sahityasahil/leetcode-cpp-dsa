class Solution {
public:
    int m, n;
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == true || grid[r][c] == '0'){
            return;
        }
        visited[r][c] = true;
        dfs(r+1, c, grid, visited);
        dfs(r, c+1, grid, visited);
        dfs(r-1, c, grid, visited);
        dfs(r, c-1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; i++){
            for (int j = 0; j <n; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(i, j, grid, visited);
                    res++;
                } 
            }
        }
        return res;
    }
};