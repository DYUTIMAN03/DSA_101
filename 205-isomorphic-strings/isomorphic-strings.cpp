class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int m = s.length();

        for(int i = 0; i < m; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
               (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};

/*
APPROACH:
1. Create two maps to store character mappings in both directions.
2. Traverse both strings simultaneously.
3. Check whether an existing mapping conflicts with the current characters.
4. If a conflict exists, return false.
5. Otherwise, store the mappings in both maps.
6. If the loop finishes, return true.

TC: O(n) average
SC: O(1), assuming a fixed character set.
*/