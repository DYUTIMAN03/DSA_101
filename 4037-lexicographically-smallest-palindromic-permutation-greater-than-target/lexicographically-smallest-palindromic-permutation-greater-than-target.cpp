class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) return "";

        // Characters available for the left half
        for (int i = 0; i < 26; i++) {
            cnt[i] /= 2;
        }

        string left = "";
        int half = s.size() / 2;

        // Build left half greedily
        for (int pos = 0; pos < half; pos++) {
            bool found = false;

            for (int c = 0; c < 26; c++) {
                if (cnt[c] == 0) continue;

                // Try this character
                cnt[c]--;
                left += char('a' + c);

                // Build the largest possible remaining palindrome
                string temp = left;

                for (int j = 25; j >= 0; j--) {
                    temp += string(cnt[j], char('a' + j));
                }

                string candidate = temp;

                if (s.size() % 2) {
                    candidate += mid;
                }

                string rev = temp;
                reverse(rev.begin(), rev.end());
                candidate += rev;

                // If even the largest completion works,
                // keep this smallest possible character
                if (candidate > target) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                cnt[c]++;
            }

            if (!found) return "";
        }

        string ans = left;

        if (s.size() % 2) {
            ans += mid;
        }

        string rev = left;
        reverse(rev.begin(), rev.end());
        ans += rev;

        return ans > target ? ans : "";
    }
};