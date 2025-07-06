class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> m;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        // this loop should be called here as we don't want the frequencies to be incremented again and again when the count func is called (so can't use it inside count)
        for (int e : n2) {
            m[e]++;
        }
    }
    
    void add(int index, int val) {
        m[n2[index]]--; // decreasing the freq of element which was present now
        n2[index] += val; // doing add operation
        m[n2[index]]++; // incrementing the freq of the current element
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int e : n1) {
            cnt += m[tot-e];
        }
        return cnt;
    }
};

// the add method modifies nums2 (via n2[index] += val), so the hash map m should track the frequencies of nums2 elements, not nums1, because nums2 is the array that changes dynamically.

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */