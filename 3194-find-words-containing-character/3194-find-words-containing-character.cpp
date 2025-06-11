class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for (int i=0; i<n; i++) {
            string curr = words[i];
            int curr_n = words[i].size();
            for (int j=0; j<curr_n; j++) {
                if (curr[j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};