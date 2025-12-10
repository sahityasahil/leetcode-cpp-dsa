class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1'000'000'007;
        int n = complexity.size();

        // If any computer i>0 has complexity[i] <= complexity[0],
        // it can never be unlocked.
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        // Otherwise, any permutation with 0 fixed first is valid.
        // Number of such permutations = (n - 1)! mod MOD.
        long long ans = 1;
        for (int i = 1; i <= n - 1; ++i) {
            ans = (ans * i) % MOD;
        }

        return (int)ans;
    }
};
