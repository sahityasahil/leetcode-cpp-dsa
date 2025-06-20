class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0, sum = nums[0]; // global sum
        maxSum = max(sum, maxSum);
        for (int i=1; i<n; i++) {
            if (nums[i] > nums[i-1]) sum += nums[i];
            else sum = nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};