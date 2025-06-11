class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the least significant digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // If digit is less than 9, simply increment and return
                digits[i]++;
                return digits;
            }
            // If digit is 9, set it to 0 and continue to next digit
            digits[i] = 0;
        }
        
        // If we're here, it means all digits were 9 (e.g., [9,9,9])
        // Create new vector with one extra digit
        vector<int> ans(n + 1);
        ans[0] = 1;  // Leading 1, rest are already 0 by default
        return ans;
    }
};