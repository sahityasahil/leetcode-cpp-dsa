class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();

        if (len == 1 && haystack.size() == 1) {
            if (haystack.compare(needle) == 0) return 0;
            else return -1;
        }
        for (int i=0; i<haystack.size(); i++) {
            if (i+len > haystack.size()) {
                return -1;
            }

            if (haystack.compare(i,len,needle) == 0) return i;
        }
        return -1;
    }
};