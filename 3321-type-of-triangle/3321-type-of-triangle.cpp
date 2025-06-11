class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        sort(nums.begin(), nums.end()); // necessary to check the existence of triangle

        if (nums[0] + nums[1] <= nums[2]) return "none";

        // we can check the number of unique elements in set to categorize the triangles
        if (s.size() == 1) return "equilateral";
        else if (s.size() == 2) return "isosceles";
        else return "scalene";
    }
};