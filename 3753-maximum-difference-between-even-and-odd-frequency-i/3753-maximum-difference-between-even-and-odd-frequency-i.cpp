class Solution {
public:
    int maxDifference(string s) {
        vector<int> m(26, 0);
        int maxOdd = 0, minEven = s.size();

        for (char c : s) m[c - 'a']++;
        for (int i=0; i<26; i++) {
            if (m[i] % 2 != 0) maxOdd = max(maxOdd, m[i]);
            if (m[i] % 2 == 0 && m[i] > 0) minEven = min(minEven, m[i]);
        } 
        return maxOdd - minEven;
    }
};