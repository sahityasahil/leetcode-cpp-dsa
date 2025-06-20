class Solution {
public:
    string clearDigits(string s) {
        string stack;
        for (char c : s) {
            if (isdigit(c)) { // isdigit() returns 1 if the value is a decimal value (0-9) else returns 0
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }
};