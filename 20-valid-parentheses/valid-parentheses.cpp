class Solution {
public:
    bool isValid(string s) {
        
        string st = "";                                      // acts like a stack
        for(char c : s) {                                    // go through each bracket
            if(c == '(' || c == '{' || c == '[') {           // opening bracket
                st.push_back(c);                             // add it
            }
            else {                                           // closing bracket
                if(st.empty())                                 // nothing to match
                    return false;

                if(c == ')' && st.back() != '(')             // ) needs (
                    return false;

                if(c == '}' && st.back() != '{')             // } needs {
                    return false;

                if(c == ']' && st.back() != '[')             // ] needs [
                    return false;
                st.pop_back();                               // remove matched bracket
            }
        }
        return st.empty();                                   // true if everything matched
    }
};