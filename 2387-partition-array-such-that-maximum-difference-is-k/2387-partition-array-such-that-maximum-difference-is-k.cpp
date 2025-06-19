class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 0, maxi = -1, mini = INT_MAX;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > maxi) maxi = nums[i];
            if (nums[i] < mini) mini = nums[i];
            int diff = abs(maxi - mini);
            if (diff <= k) {
                ans.push_back(nums[i]);
            }

            else {
                cnt++;
                ans.clear();
                mini = INT_MAX;
                maxi = -1;
                i--;
            }
        }
        return cnt+1;
    }
};