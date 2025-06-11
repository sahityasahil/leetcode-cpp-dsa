class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        for(int i=0; i<size; i++) {
            if (nums[i] == 0) {
                if (i+2 < size) {
                nums[i] = 1;
                nums[i+1] = nums[i+1]^1;
                nums[i+2] = nums[i+2]^1;
                cnt++;
                }
                else return -1;
            }
        }
        return cnt;
    }
};