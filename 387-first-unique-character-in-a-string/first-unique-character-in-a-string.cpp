class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int n = s.size();

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            arr[ch - 'a']++;
        }
        for(int i = 0; i < n; i++) {
            if(arr[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

/*
Approach: Frequency Array

1. Create an array of size 26 to store character frequencies.
2. Traverse the string and count each character.
3. Traverse the string again from left to right.
4. Return the index of the first character whose frequency is 1.
5. If no such character exists, return -1.

TC: O(n)
SC: O(1), since the frequency array has fixed size 26.
*/