class Solution {
public:

    bool allZeroes(const vector<int>& counter) {
        for (int i : counter) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string &txt, string &pat) {

        int n = txt.size();
        int k = pat.size();

        vector<int> counter(26, 0);
        vector<int> result;

        // Count frequency of characters in pattern
        for (int i = 0; i < k; i++) {
            char ch = pat[i];
            counter[ch - 'a']++;
        }

        int i = 0;
        int j = 0;

        while (j < n) {

            // Add txt[j] to window
            counter[txt[j] - 'a']--;

            // Window has reached pattern size
            if (j - i + 1 == k) {

                // Current window is an anagram
                if (allZeroes(counter)) {
                    result.push_back(i);
                }

                // Remove txt[i] from window
                counter[txt[i] - 'a']++;

                // Move left pointer
                i++;
            }

            // Move right pointer
            j++;
        }

        return result;
    }
};