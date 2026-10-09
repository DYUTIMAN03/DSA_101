class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0; // Insertions needed
        int count = 0;  // Unmatched '('
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            }
            else if(s[i] == ')') {
                if(count > 0) count--;
                else result++; // Insert '('

                if(i+1 < n && s[i+1] == ')') {
                    i += 2; // Consume '))'
                }
                else {
                    result++; // Insert missing ')'
                    i++;
                }
            }
        }
        return result + (count * 2); // Each '(' needs two ')'
    }
};