class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int targetFreq = n/2;
        for (int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        for (auto pair : mpp) {
            if (pair.second > targetFreq) {
                return pair.first;
            }
        }
        return -1;
    }
};