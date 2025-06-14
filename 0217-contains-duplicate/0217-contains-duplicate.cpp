class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i=0; i<n; i++) {
            m[nums[i]]++;    
        }

        for (const auto& e : m) {
            int key = e.first;
            int value = e.second;
            if (value > 1) return true;
        }
        return false;
    }
};