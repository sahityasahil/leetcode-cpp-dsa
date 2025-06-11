class Solution {
public:    
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto e : words) m[e]++; // storing the freq in hashmap

        int cnt=0, alreadyPalindrome=0; 
        for (auto& [e, freq] : m) {
            string s = e;
            // if reverse of e is there in the array then the word as well as the reverse of it can be appended to get a palindrome
            reverse(s.begin(), s.end());

            // checking if the current word is already a palindrome in itself, it means it can be appended at right and left end (if freq >=2) or in the middle if it has an odd freq.

            /*  As palindrome strings with a frequency >= 2 can be inserted on left & right.
This means that any palindrome string with an even frequency can be inserted on left & right.
That is, let's say a palindrome string has frequency 4, it can be inserted 2 times on left and 2 times on right.

So we can simply count the number of insertion as (freq / 2), that is, insertions one from the left and one from the right so basically half of it.
            */
            if (e == s) {
                cnt += (freq/2)*4;
                if (freq % 2) alreadyPalindrome = 1;
            }
            else if (e < s && m.count(s)) {
                cnt += min(freq, m[s]) * 4;
            }
        }
        return cnt + alreadyPalindrome*2;
    }
};