#include <vector>
#include <numeric> // For std::accumulate (though a loop is fine too)
#include <unordered_set> // For efficient lookup

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        // Step 1: Find the sum of the longest sequential prefix.
        long long current_prefix_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                current_prefix_sum += nums[i];
            } else {
                // The sequential prefix breaks here
                break;
            }
        }

        // Step 2: Store all numbers from nums into a hash set for efficient lookup.
        std::unordered_set<int> num_set(nums.begin(), nums.end());

        // Step 3: Find the smallest integer x, starting from current_prefix_sum,
        // that is not present in nums.
        int x = static_cast<int>(current_prefix_sum);
        while (num_set.count(x)) {
            x++;
        }

        return x;
    }
};