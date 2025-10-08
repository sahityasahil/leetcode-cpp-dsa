class Solution {
public:
    void binSearch(vector<int>& spells, vector<int>& potions, int idx, int m, long long success, vector<int>&ans) {
        long long left = 0, right = m-1;
        while (right > left) {
            long long mid = left + (right-left)/2;
            long long mul = (long long)potions[mid] * spells[idx];
            if (success > mul) {
                left = mid+1;
            }
            else if (success <= mul) {
                right = mid;
            }
        }
        ans[idx] = m-right;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());

        for (int i=0; i<n; i++) {
            long long mul = (long long)potions[m-1] * spells[i];
            if (mul < success) ans[i] = 0;
            
            else {
                binSearch(spells, potions, i, m, success, ans);
            }
        }
        return ans;
    }
};