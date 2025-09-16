class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        int ht[26] = {0};
        for (char c : brokenLetters) {
            ht[c - 'a'] = 1;
        }
        
        bool canType = true;
        for (int i = 0; i <= text.length(); i++) {
            // Treat end of string or space as word boundary
            if (i == text.length() || text[i] == ' ') {
                if (canType) {
                    cnt++;
                }
                canType = true; // Reset for next word
            } else {
                // Check if current character is broken
                if (ht[text[i] - 'a'] != 0) {
                    canType = false; // Word cannot be typed
                }
            }
        }
        return cnt;
    }
};