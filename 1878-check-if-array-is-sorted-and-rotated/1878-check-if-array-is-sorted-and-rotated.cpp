class Solution {
public:
 bool checkSorted(vector<int>& arr) {
        for (int i=0; i<arr.size()-1; i++) {
            if (arr[i+1] < arr[i]) {
                return 0;
            }
        }
        return 1;
    }

    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if (checkSorted(nums)) {
            return 1;
        }

        if (nums[0] < nums[n-1]) cnt++;
        for (int i=0; i<n-1; i++) {
            if (nums[i] > nums[i+1]) {
                cnt++;
            }
        }
        if (cnt == 1) return 1;
        else return 0;
    }
};