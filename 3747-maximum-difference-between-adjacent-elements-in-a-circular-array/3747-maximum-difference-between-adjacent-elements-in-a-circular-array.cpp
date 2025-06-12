class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i=0; i<n-1; i++) {
            int diff = abs(nums[i] - nums[i+1]);
            if (diff > maxi) {
                maxi = diff;
            }
        }
        int diff2 = abs(nums[0] - nums[n-1]);
        if (diff2 > maxi) return diff2;
        else return maxi;
    }
};