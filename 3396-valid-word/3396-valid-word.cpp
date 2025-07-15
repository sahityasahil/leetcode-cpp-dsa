class Solution {
public:
    bool isValid(string word) {
        int vowFlag = 0, consFlag = 0;
        if (word.length() < 3) return false;
        for (int i=0; i<word.length(); i++) {
            if (isdigit(word[i])) {
                continue;
            }
            else if (isalpha(int(word[i]))) {
                if (word[i] == 'a' || word[i] == 'A' || 
                word[i] == 'e' || word[i] == 'E' ||
                word[i] == 'i' || word[i] == 'I' ||
                word[i] == 'o' || word[i] == 'O' ||
                word[i] == 'u' || word[i] == 'U') {
                    vowFlag = 1;
                }
                else consFlag = 1;
            }
            else return false;
        }
        if (vowFlag == 1 && consFlag == 1) return true;
        else return false;
    }
};