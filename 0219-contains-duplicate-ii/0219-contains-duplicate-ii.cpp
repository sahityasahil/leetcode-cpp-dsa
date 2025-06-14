class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            int val = nums[i];
            if (m.find(val) != m.end() && i - m[val] <= k) {
                return true;
            }
            m[val] = i;
        }
        return false;        
    }
};