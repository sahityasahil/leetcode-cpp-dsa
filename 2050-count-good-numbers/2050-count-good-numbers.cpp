class Solution {
public:
    // Function to calculate (x^n) % mod efficiently
    long long modPow(long long x, long long n, int mod) {
        long long result = 1;
        x %= mod;
        
        while (n > 0) {
            // If n is odd, multiply result with x
            if (n % 2 == 1) {
                result = (result * x) % mod;
            }
            
            // n = n/2
            n >>= 1;
            // x = x^2
            x = (x * x) % mod;
        }
        
        return result;
    }
    
    int countGoodNumbers(long long n) {
        const int MOD = 1000000007;
        
        // Calculate number of even and odd positions
        long long evenPositions = (n + 1) / 2; // Ceiling of n/2
        long long oddPositions = n / 2;        // Floor of n/2
        
        // 5 choices for even positions (0,2,4,6,8)
        // 4 choices for odd positions (2,3,5,7)
        long long result = 1;
        
        // Calculate 5^evenPositions % MOD
        long long evenContribution = modPow(5, evenPositions, MOD);
        // Calculate 4^oddPositions % MOD
        long long oddContribution = modPow(4, oddPositions, MOD);
        
        // Combine the results
        result = (evenContribution * oddContribution) % MOD;
        
        return (int)result;
    }
};