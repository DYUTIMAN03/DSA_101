
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        string curr;

        function<void(int)> solve = [&](int idx) {
            if(idx == digits.size()) {
                ans.push_back(curr);
                return;
            }
            for(char c : mp[digits[idx]]) {
                curr.push_back(c);
                solve(idx + 1);
                curr.pop_back();
            }
        };
        solve(0);
        return ans;
    }
};
