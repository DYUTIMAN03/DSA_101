class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i] = how many characters of word2
        // can be matched as a suffix starting from word1[i]
        vector<int> dp(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i]++;
                j--;
            }
        }

        vector<int> ans;
        int pos = 0;
        bool changed = false;

        for (int i = 0; i < n && pos < m; i++) {

            // Exact match
            if (word1[i] == word2[pos]) {
                ans.push_back(i);
                pos++;
            }

            // Use our one allowed mismatch
            else if (!changed && dp[i + 1] >= m - pos - 1) {
                ans.push_back(i);
                pos++;
                changed = true;
            }
        }

        if (pos == m)
            return ans;

        return {};
    }
};