/*class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        int score = 0;
        int depth = 0;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                depth++;
            } 
            else{
                depth --;
                if(s[i-1]=='('){
                score += (1 << depth); 
                }
            } 
        }
        return score;
    }
};
*/

//Approach-1 (Using stack or vector as stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        vector<int> vec;

        int score = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                vec.push_back(score);
                score = 0;
            } else {
                if (s[i-1] == '(') { //we found inner most "()" -> +1 point
                    score = vec.back() + 1;
                } else {
                    // had content inside -> double it
                    score = vec.back() + (2 * score);
                }
                vec.pop_back();
            }
        }
        return score;
    }
};