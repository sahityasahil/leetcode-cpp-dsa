class Solution {
public:
    int countOdds(int low, int high) {
        // int ans = 0;
        int diff = high-low; 
        if (diff%2 != 0) {
            return (int)(diff/2)+1;
        }
        else {
            if (low%2 != 0) {
                return (int)(diff/2)+1;
            }
            else return (int)(diff/2); 
        }
    }
};