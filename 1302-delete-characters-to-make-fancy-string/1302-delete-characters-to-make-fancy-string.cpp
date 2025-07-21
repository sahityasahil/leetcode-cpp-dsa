class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int n = s.length();
        
        // Handle empty or single-character strings
        if (n <= 2) return s;
        
        // Add first two characters
        result += s[0];
        if (n > 1) result += s[1];
        
        // Process the rest of the string
        for (int i = 2; i < n; i++) {
            // Add current character only if it doesn't form three consecutive identical characters
            if (s[i] != s[i-1] || s[i] != s[i-2]) {
                result += s[i];
            }
        }
        return result;
    }
};