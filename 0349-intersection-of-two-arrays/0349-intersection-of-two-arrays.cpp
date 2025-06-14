class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end()); // Store nums1 elements in a set
        vector<int> result;
        
        for (int num : nums2) {
            if (s.find(num) != s.end()) { // If num is in the set
                result.push_back(num);    // Add to result
                s.erase(num);             // Remove from set to avoid duplicates
            }
        }
        
        return result;
    }
};