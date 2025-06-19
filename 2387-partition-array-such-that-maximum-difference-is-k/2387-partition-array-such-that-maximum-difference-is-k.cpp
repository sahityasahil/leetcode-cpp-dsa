class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n= nums.size();
        int count =0;
        while(j<n){
            if(nums[j] - nums[i] > k){
                i = j;
                count++;
                continue;
            }
            j++;
        }
        return count+1;
    }
};