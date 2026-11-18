class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i <= n - m; i++) { //can also use n
            int j;
            for(j = 0; j < m; j++) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if(j == m) {
                return i;
            }
        }
        return -1;
    }
};

/*
APPROACH:
1. i selects the starting position in haystack.
2. j compares characters of needle with haystack.
3. If characters mismatch, break the inner loop.
4. Try the next starting position.
5. If j == m, all characters matched. Return i.
6. If no match is found, return -1.

TC: O(n * m)
SC: O(1)
*/