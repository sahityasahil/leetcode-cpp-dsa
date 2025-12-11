class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n + 1);
        vector<int> minRow(n + 1, n + 1); // minimum value will always be less than n+1
        vector<int> maxCol(n + 1);
        vector<int> minCol(n + 1, n + 1); // minimum value will always be less than n+1

        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            // searching max and min value vertically
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);

            // searching max and min value horizontally
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        int res = 0;
        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
                res++;
            }
        }
        return res;
    }
};