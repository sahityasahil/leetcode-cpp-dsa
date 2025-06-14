class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i=0; i<n; i++) {
            if(m.find(nums[i]) != m.end()) return true;
            else m[nums[i]] = 1;
        }
        return false;
    }
};