class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        // After sorting, the first string (strs[0]) and the last string (strs[n-1]) will be the most "different" in terms of their prefixes

        // Any prefix common to all strings must be common to the first and last strings, because they are the extremes in the sorted order
        int n = strs.size();
        string first = strs[0], last = strs[n-1];
        for (int i=0; i<min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) return ans;
            ans += first[i];
        }
        return ans;
    }
};