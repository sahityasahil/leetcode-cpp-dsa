class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        // stringstream to break the version strings into tokens at each dot (.)
        string token1, token2;
        while (s1.good() || s2.good()) {
            // .good() checks if there’s more data to read from
            if (!getline(s1, token1, '.')) token1 = "0";
            if (!getline(s2, token2, '.')) token2 = "0";

            /* 
            getline(s1, token1, '.') reads the next part of version1 up to the next dot and stores it in token1.
If getline fails (because there are no more tokens), it sets token1 to "0". This handles cases where one version is shorter, like "1.2" vs. "1.2.3". The shorter version is treated as if it has trailing zeros (e.g., "1.2" becomes "1.2.0")
            */
            
            int num1 = stoi(token1);
            int num2 = stoi(token2);

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }
};