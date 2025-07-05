class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int lucky = -1;
        for (int num : arr) {
            freq[num]++;
        }
        for (auto& [key, value] : freq) {
            if (key == value) {
                lucky = max(lucky, key);
            }
        }
        return lucky;
    }
};