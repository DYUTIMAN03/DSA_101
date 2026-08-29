class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> idx(n);

        // Store indices: 0, 1, 2, ...
        iota(idx.begin(), idx.end(), 0);

        // Sort indices according to their values in nums
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> ans(n);

        for (int i = 0; i < n; ) {
            int j = i + 1;

            // Find one swappable group
            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            // Get the original indices of this group
            vector<int> positions(idx.begin() + i, idx.begin() + j);

            // Sort positions from left to right
            sort(positions.begin(), positions.end());

            // Put smallest values at smallest positions
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};