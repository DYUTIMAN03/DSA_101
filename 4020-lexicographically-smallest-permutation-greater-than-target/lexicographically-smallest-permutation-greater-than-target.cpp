class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try making the first difference at position i
        for (int i = n - 1; i >= 0; i--) {

            int freq[26];
            copy(begin(cnt), end(cnt), begin(freq));

            bool possible = true;

            // Match target[0...i-1]
            for (int j = 0; j < i; j++) {
                int ch = target[j] - 'a';

                if (freq[ch] == 0) {
                    possible = false;
                    break;
                }

                freq[ch]--;
            }

            if (!possible) continue;

            // Find smallest available character > target[i]
            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {
                if (freq[ch] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + ch);
                    freq[ch]--;

                    // Add remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        ans += string(freq[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};