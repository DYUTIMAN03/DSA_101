class Solution {
public:
    bool isValid(string s) {

        string st = "";

        for(char c : s) {

            // Opening bracket
            if(c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            }

            // Closing bracket
            else {

                // Nothing to match
                if(st.empty())
                    return false;

                // Check matching pair
                if(c == ')' && st.back() != '(')
                    return false;

                if(c == '}' && st.back() != '{')
                    return false;

                if(c == ']' && st.back() != '[')
                    return false;

                // Matching bracket found, remove it
                st.pop_back();
            }
        }

        // If nothing is left, everything matched
        return st.empty();
    }
};