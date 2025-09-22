class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int sum = 0, highestCnt = 0;
        for (int i : nums) {
            mpp[i]++;
            if (mpp[i] > highestCnt) highestCnt = mpp[i];
        }
        for (const auto& pair : mpp) {
            if (pair.second == highestCnt) sum = (sum + pair.second);
        }
        return sum;
    }
};