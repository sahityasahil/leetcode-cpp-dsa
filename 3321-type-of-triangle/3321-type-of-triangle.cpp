class Solution {
public:
    bool triangleCheck(vector<int>& nums) {
        if (((nums[0]+nums[1]) > nums[2]) && ((nums[1]+nums[2]) > nums[0]) && ((nums[0]+nums[2]) > nums[1])) {
            return true;
        }
        else return false;
    }
    
    string triangleType(vector<int>& nums) {
        if (triangleCheck(nums)) {
            if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
            }

            else if ((nums[0] == nums[1]) || (nums[1] == nums[2]) || (nums[0] == nums[2])) {
            return "isosceles";
            }
            else return "scalene";
        }
        else return "none";
    }
};