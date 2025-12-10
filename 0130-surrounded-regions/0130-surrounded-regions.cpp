class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, int m, int n) {
        // Out of bounds or not an 'O' -> stop
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O') {
            return;
        }

        // Mark this 'O' as safe (connected to border)
        board[r][c] = '#';

        // Explore 4-directionally
        dfs(r + 1, c, board, m, n); // down
        dfs(r - 1, c, board, m, n); // up
        dfs(r, c + 1, board, m, n); // right
        dfs(r, c - 1, board, m, n); // left
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // 1) Mark all 'O's connected to the border as safe ('#')
        
        // First and last row
        for (int c = 0; c < n; ++c) {
            if (board[0][c] == 'O') {
                dfs(0, c, board, m, n);
            }
            if (board[m-1][c] == 'O') {
                dfs(m-1, c, board, m, n);
            }
        }

        // First and last column
        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') {
                dfs(r, 0, board, m, n);
            }
            if (board[r][n-1] == 'O') {
                dfs(r, n-1, board, m, n);
            }
        }

        // 2) Flip the remaining 'O' to 'X', and '#' back to 'O'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';   // surrounded region
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';   // safe region
                }
            }
        }
    }
};
