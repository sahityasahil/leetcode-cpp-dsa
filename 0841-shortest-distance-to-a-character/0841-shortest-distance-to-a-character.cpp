// this code has a better time complexity O(n)

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int size = s.length();
        vector<int> ans(size);
        
        // Left to right pass
        int prev = INT_MAX; // Previous occurrence of c (infinity if none yet)
        for (int i = 0; i < size; i++) {
            if (s[i] == c) {
                prev = i;
            }
            ans[i] = (prev == INT_MAX) ? INT_MAX : i - prev;
        }
        
        // Right to left pass
        prev = INT_MAX; // Next occurrence of c (infinity if none yet)
        for (int i = size - 1; i >= 0; i--) {
            if (s[i] == c) {
                prev = i;
            }
            ans[i] = min(ans[i], (prev == INT_MAX) ? INT_MAX : prev - i);
        }
        
        return ans;
    }
};