class Solution {
public:
    int maxDistance(string s, int k) {
        int vertical = 0, horizontal = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    vertical++;
                    break;
                case 'S':
                    vertical--;
                    break;
                case 'E':
                    horizontal++;
                    break;
                case 'W':
                    horizontal--;
                    break;
            }
            ans = max(ans, min(abs(vertical) + abs(horizontal) + k * 2, i + 1)); // i+1 for the case if k is very huge but we can't iterate more than the string's length so string length will be the ans itself
            // 2*k because if we change one letter then it will result in addition of 2 unit distance
            // eg. NS => cancels out => d = 0
            // but if k=1, we will change S to N or N to S, either of them will return d = 2 (i.e. 2*k) 
        }
        return ans;
    }
};