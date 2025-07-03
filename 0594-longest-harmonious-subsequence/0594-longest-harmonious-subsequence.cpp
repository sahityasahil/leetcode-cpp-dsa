class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int j = 0, maxLength = 0;

        for (int i=0; i<n; i++) {
            while (nums[i] - nums[j] > 1) {
                j++;
            }
            if (nums[i] - nums[j] == 1) {
                maxLength = max(maxLength, i - j + 1);
            }
        }
        return maxLength;
    }
};

// 1 2 2 2 3 3 5 7