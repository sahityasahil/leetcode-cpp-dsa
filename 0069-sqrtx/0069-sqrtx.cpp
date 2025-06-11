class Solution {
public:
    int mySqrt(int x) {
        // base cases
        if (x == 0) return 0;
        if (x == 1) return 1;
        
        long long left = 1;
        long long right = x;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == x) {
                return mid;
            }
            else if (square < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};