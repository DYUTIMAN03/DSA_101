class Solution {
public:
    bool checkString(string s) {
        string ans = s;
        sort(ans.begin(), ans.end());

        if(s == ans) return true;
        else return false;
    }
};