class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size();
        int n = s.size();
        int i = 0, j = 0;

        while(i < m && j < n) {
            if(g[i] <= s[j]) {
                i++;  // Child is satisfied
                j++;  // Cookie is used
            }
            else {
                j++;  // Cookie is too small, try the next one
            }
        }
        return i;
    }
};