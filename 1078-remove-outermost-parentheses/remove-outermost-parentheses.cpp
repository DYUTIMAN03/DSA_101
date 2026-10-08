class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int count = 0;
        string result = "";

        for(auto &ch: s){
            if(ch == '('){
                if(count != 0) result.push_back(ch);
                count++;
            }
            else if(ch == ')'){
                count--;
                if(count != 0) result.push_back(ch);
            }
        }
        return result;
    }
};