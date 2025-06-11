class Solution {
public:

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) return ch;
        else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool isValid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')) return 1;
        else return 0;
    }

    bool checkPalindrome(string s)
{
    int st=0, e=s.length()-1;
    
    while (st <= e) {

        if (s[st] != s[e]) return 0;
        else {
            st++;
            e--;
        }
    }
    return 1;
}

    bool isPalindrome(string s) {
        string temp = "";
        for (int i=0; i<s.length(); i++) {
            if (isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }
        for (int j=0; j<temp.length(); j++) {
            temp[j] = toLowerCase(temp[j]);
        }
        return checkPalindrome(temp);
    }
};