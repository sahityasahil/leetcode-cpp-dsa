class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = 1, inc = 1, dec = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) inc++, dec = 1;      // Case - strictly increasing
            else if (nums[i] < nums[i-1]) dec++, inc = 1; // Case - strictly decreasing
            else inc = dec = 1;                           
            maxLen = max(maxLen, max(inc, dec));          
        }
        return maxLen;
    }
};  