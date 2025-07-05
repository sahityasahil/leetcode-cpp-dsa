class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), lucky = -1;
        int maxval = arr[n-1];
        vector<int> v(500, 0);
        for (int e : arr) {
            v[e-1]++;
        }
        for (int i=0; i<maxval; i++) {
            if (v[i] == i+1) lucky = i+1;
        }
        return lucky;
    }
};