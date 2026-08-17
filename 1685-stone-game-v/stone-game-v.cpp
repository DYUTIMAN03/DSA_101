#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n == 1) {
            return 0; // Game ends, score is 0
        }

        // Precompute prefix sums
        // prefixSum[k] will store the sum of stoneValue[0...k-1]
        std::vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        // dp[i][j] stores the maximum score Alice can get from stones stoneValue[i...j]
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // Iterate over sub-array lengths (len)
        // len goes from 2 to n because single stones are base cases (dp[i][i] = 0)
        for (int len = 2; len <= n; ++len) {
            // Iterate over starting index i
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index j

                // Alice tries all possible split points k
                // k goes from i to j-1 (ensuring both left and right parts are non-empty)
                for (int k = i; k < j; ++k) {
                    // Sum of the left part stoneValue[i...k]
                    int sum_left = prefixSum[k + 1] - prefixSum[i];
                    // Sum of the right part stoneValue[k+1...j]
                    int sum_right = prefixSum[j + 1] - prefixSum[k + 1];

                    int current_score = 0;
                    if (sum_left < sum_right) {
                        // Bob throws away right, Alice gets sum_left and continues with left part
                        current_score = sum_left + dp[i][k];
                    } else if (sum_right < sum_left) {
                        // Bob throws away left, Alice gets sum_right and continues with right part
                        current_score = sum_right + dp[k + 1][j];
                    } else { // sum_left == sum_right
                        // Alice decides which to throw away to maximize future score
                        current_score = sum_left + std::max(dp[i][k], dp[k + 1][j]);
                    }
                    
                    dp[i][j] = std::max(dp[i][j], current_score);
                }
            }
        }

        return dp[0][n - 1];
    }
};