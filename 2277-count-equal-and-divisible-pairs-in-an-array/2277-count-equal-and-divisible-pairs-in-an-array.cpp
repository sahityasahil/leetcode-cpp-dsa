class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((i*j)%k == 0 && (nums[i] == nums[j])) cnt++;
            }
        }
        return cnt;
    }
};