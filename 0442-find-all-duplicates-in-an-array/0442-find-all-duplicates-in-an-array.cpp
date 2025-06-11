class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> hash(n, 0);

        for (auto e : nums) {
            hash[e-1]++;
            if (hash[e-1] > 1) {
                ans.push_back(e);
            }
        }
        return ans;
    }
};