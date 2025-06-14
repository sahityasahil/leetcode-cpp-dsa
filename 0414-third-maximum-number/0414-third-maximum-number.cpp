class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int n = s.size();
        if (n < 3) {
            return *s.rbegin(); // Return maximum if fewer than 3 distinct elements
        }
        auto it = s.rbegin();
        auto it3 = next(it, 2); // Move to third largest
        return *it3;
    }
};