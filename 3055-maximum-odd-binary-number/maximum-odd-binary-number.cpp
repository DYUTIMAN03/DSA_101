class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n, '0');
        int i = 0;

        for(char &ch : s) {
            if(ch == '1') {
                if(result[n-1] == '1') {
                    result[i] = '1';
                    i++;
                }
                else {
                    result[n-1] = '1';
                }
            }
        }
        return result;
    }
};

/*
Approach: Greedy

1. Initialize result with all zeros.
2. Traverse the original string.
3. Place the first '1' at the last position to make
   the binary number odd.
4. Place all remaining '1's from the left.
5. Return the resulting string.

TC: O(n)
SC: O(n)
*/