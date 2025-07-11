class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        int num = 0, moreReq = 0;
        for (int i=0; i<n; i++) {
            num = nums[i];
            moreReq = target - num;
            if (mpp.find(moreReq) != mpp.end()) {
                return {mpp[moreReq], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};