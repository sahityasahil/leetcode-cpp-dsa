class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
    
        int padding = (k - (n % k)) % k;  // Handles case when n%k == 0
        s.append(padding, fill);
        
        for (int i=0; i<n; i+=k) {
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};