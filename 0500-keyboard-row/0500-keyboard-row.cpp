class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> rowMap;
        string row1 = "qwertyuiop", row2 = "asdfghjkl", row3 = "zxcvbnm";
        
        // mapping all the letters to their corresponding rows
        for (char c : row1) rowMap[c] = 1;
        for (char c : row2) rowMap[c] = 2;
        for (char c : row3) rowMap[c] = 3;
        
        vector<string> result;
        
        // taking one word at a time from the array of words
        for (string word : words) {
            // taking the first alphabet from the first word to know or have a reference row for the remaining alphabets of the word
            int row = rowMap[tolower(word[0])]; 
            bool isValid = true;
            
            for (char c : word) {
                if (rowMap[tolower(c)] != row) {
                    isValid = false;
                    break;
                }
            }
            
            // if we are here, then all the alphabets of the current word belongs to "row" which was the reference taken from the first alphabet
            if (isValid) result.push_back(word);
        }
        return result;
    }
};