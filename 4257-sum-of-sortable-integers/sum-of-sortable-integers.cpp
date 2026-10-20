class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, 1e9);
        vector<int> prefDrop(n, 0);

        // Maximum element before each index
        for(int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Minimum element from each index to the end
        for(int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Count adjacent decreases up to each index
        for(int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        // Check whether block size k is sortable
        auto check = [&](int k) {
            for(int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Count decreases inside this block
                int drops = prefDrop[end] - prefDrop[start];

                // Also check the circular connection
                if(nums[end] > nums[start]) {
                    drops++;
                }

                // Block must be rotatable into sorted order,
                // and all earlier elements must be <= later ones
                if(drops > 1 || prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int result = 0;

        // Enumerate divisors of n
        for(int k = 1; k <= n / k; k++) {
            if(n % k == 0) {
                if(check(k)) {
                    result += k;
                }

                int other = n / k;

                if(other != k && check(other)) {
                    result += other;
                }
            }
        }

        return result;
    }
};

/*
Approach: Divisor Enumeration + Prefix/Suffix Arrays

1. Find prefix maximums, suffix minimums, and adjacent decreases.
2. Enumerate every divisor k of n.
3. For each block of length k, check whether it can be
   cyclically rotated into sorted order.
4. Ensure elements from earlier blocks can remain before
   all elements in later blocks.
5. Add k if every block passes.

TC: O(n + sum(n/k for each divisor k of n))
SC: O(n)
*/