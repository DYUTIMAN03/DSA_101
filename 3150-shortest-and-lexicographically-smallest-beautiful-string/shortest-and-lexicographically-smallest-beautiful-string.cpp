class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int left = 0;
        int count_ones = 0;
        int min_len = INT_MAX; // To store the length of the shortest beautiful substring
        string result = "";    // To store the lexicographically smallest beautiful substring

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                count_ones++;
            }

            // While the current window has k ones, process it and try to shrink from the left
            while (count_ones == k) {
                int current_len = right - left + 1;
                string current_substring = s.substr(left, current_len);

                if (current_len < min_len) {
                    min_len = current_len;
                    result = current_substring;
                } else if (current_len == min_len) {
                    // If lengths are equal, compare lexicographically
                    if (result == "" || current_substring < result) { // handle initial empty result
                        result = current_substring;
                    }
                }

                // Shrink the window from the left
                if (s[left] == '1') {
                    count_ones--;
                }
                left++;
            }
        }
        return result;
    }
};