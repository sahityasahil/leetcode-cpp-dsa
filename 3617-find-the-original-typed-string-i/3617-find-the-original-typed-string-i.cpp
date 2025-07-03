class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int cnt = 1;
        // char temp = '';
        for (int i=1; i<n; i++) {
            if (word[i] == word[i-1]) cnt++;
        }
        return cnt;
    }
};