class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for(int j = i; j < n; j++) {

                // Prevent integer overflow
                if(prod > 25200 / nums[j]) {
                    break;
                }
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, (long long)nums[j]);

                if(prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

// Approach:
// 1. Use two nested loops to generate all possible contiguous subarrays.
// 2. For each starting index i, initialise product, GCD and LCM.
// 3. Expand the subarray using j and update product, GCD and LCM incrementally.
// 4. If product == GCD * LCM, update the maximum subarray length.
// 5. Return the maximum valid length.

// T.C: O(n^2 * log M), where M is the maximum element.
// S.C: O(1)