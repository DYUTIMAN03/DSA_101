/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (char &ch : s) {
            mp[ch]++;
        }
        for (char &ch : t) {
            mp[ch]--;
            if (mp[ch] < 0) {
                return ch;
            }
        }
        return 'x';
    }
};
*/


class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_s = 0;
        int sum_t = 0;

        for (char &ch : s) {
            sum_s += ch;
        }
        for (char &ch : t) {
            sum_t += ch;
        }
        return (char)(sum_t - sum_s);
    }
};

/*
int sum = 0;

for (char &ch : t)
    sum += ch;
for (char &ch : s)
    sum -= ch;
    
return (char)sum;
*/

/*
int XOR = 0;

for (char &ch : s)
    XOR ^= ch;

for (char &ch : t)
    XOR ^= ch;

return (char)XOR;
*/