class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return 0;
        }
        return grid[row][col];
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        // the intuition for this problem is surrounded all the sides =>
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int s = dfs(grid, i + 1, j)+dfs(grid, i - 1, j)+dfs(grid, i, j + 1)+dfs(grid, i, j - 1);
                    perimeter += 4-s;
                }
            }
        }
        return perimeter;
    }
};