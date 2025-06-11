class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count frequency of each digit
        vector<int> freq(10, 0);
        int evenCount = 0;
        int totalDigits = digits.size();
        
        for (int d : digits) {
            freq[d]++;
            if (d % 2 == 0) evenCount++;
        }
        
        set<int> result;
        
        // For each possible last digit (must be even)
        for (int ones = 0; ones <= 9; ones += 2) {
            if (freq[ones] == 0) continue;  // Skip if we don't have this even digit
            
            // For each possible tens digit
            for (int tens = 0; tens <= 9; tens++) {
                if (freq[tens] == 0) continue;
                if (tens == ones && freq[tens] < 2) continue;
                
                // For each possible hundreds digit (can't be 0)
                for (int hundreds = 1; hundreds <= 9; hundreds++) {
                    if (freq[hundreds] == 0) continue;
                    if (hundreds == ones && freq[hundreds] < 2) continue;
                    if (hundreds == tens && freq[hundreds] < 2) continue;
                    if (hundreds == ones && hundreds == tens && freq[hundreds] < 3) continue;
                    
                    // Check if we have enough of each digit
                    vector<int> tempFreq = freq;
                    tempFreq[hundreds]--;
                    tempFreq[tens]--;
                    tempFreq[ones]--;
                    
                    if (tempFreq[hundreds] >= 0 && 
                        tempFreq[tens] >= 0 && 
                        tempFreq[ones] >= 0) {
                        int num = hundreds * 100 + tens * 10 + ones;
                        result.insert(num);
                    }
                }
            }
        }
        return result.size();
    }
};