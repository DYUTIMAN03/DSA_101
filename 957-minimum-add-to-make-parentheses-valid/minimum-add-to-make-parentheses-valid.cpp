class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int insertions = 0;

        for(auto &ch: s){
            if(ch == '('){
                balance++;
            }
            else if(ch == ')'){
                if(balance > 0) balance --;
                else insertions ++;
            }
        }
        insertions += balance;
        return insertions;
    }
};