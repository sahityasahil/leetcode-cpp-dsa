class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int e : nums) {
            int digit = e;
            int cnt = 0;
            while (digit != 0) {
                digit = digit/10;
                cnt++;
            }
            if (cnt%2 == 0) ans++;
        }
        return ans;
    }
};