class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) cnt++;
        }
        for (int j=0; j<cnt; j++) {
            for (int k=0; k<n-1; k++) {
                if ((nums[k] == 0) && (nums[k+1] != 0)) swap(nums[k], nums[k+1]);
            }
        }
    }
};