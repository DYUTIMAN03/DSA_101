/*
class Solution {
public:
    bool isValid(string str) {
        int sum = 0;
        for(char ch:str) {
            if(ch == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
                return false;
        }
        return sum==0;
    }
    void generate(string curr, int n, int length, vector<string>& result) {
        if(length == 2*n) {
            if(isValid(curr))
                result.push_back(curr);
            return;
        }
        
        curr.push_back('(');
        generate(curr, n, length+1, result);
        curr.pop_back();
        curr.push_back(')');
        generate(curr, n, length+1, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        generate("", n, 0, result);
        return result;
    }
};
*/

class Solution {
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n, curr, 0, 0);
        return result;
    }
};
