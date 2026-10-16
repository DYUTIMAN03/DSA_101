class Solution {
private:
    const long long MOD = 1e9 + 7;

    vector<long long> sum, sqSum, lazy;
    int n;

    // Apply an increment to every value in this segment
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // (x + val)^2 = x^2 + 2*val*x + val^2
        sqSum[node] = (
            sqSum[node]
            + 2 * val * sum[node]
            + len * val * val
        ) % MOD;

        sum[node] = (sum[node] + len * val) % MOD;

        // Remember the pending update for children
        lazy[node] = (lazy[node] + val) % MOD;
    }

    // Pass pending updates to the children
    void push(int node, int l, int r) {
        if(lazy[node] == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    // Increase every value in range [ql, qr] by val
    void update(int node, int l, int r,
                int ql, int qr, long long val) {

        if(ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        if(ql <= mid)
            update(node * 2, l, mid, ql, qr, val);

        if(qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr, val);

        // Combine results from both children
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;

        sqSum[node] = (
            sqSum[node * 2] + sqSum[node * 2 + 1]
        ) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sqSum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastSeen;
        long long result = 0;

        for(int r = 0; r < n; r++) {
            int prev = -1;

            if(lastSeen.count(nums[r]))
                prev = lastSeen[nums[r]];

            // These subarrays gain one distinct value
            update(1, 0, n - 1, prev + 1, r, 1);

            lastSeen[nums[r]] = r;

            // Root stores the squared-count sum for all
            // subarrays ending at index r
            result = (result + sqSum[1]) % MOD;
        }

        return result;
    }
};

/*
Approach: Segment Tree + Lazy Propagation

1. Process each element as the right endpoint of subarrays.
2. Find its previous occurrence using lastSeen.
3. Increase distinct counts for starting indices in
   [previous occurrence + 1, current index].
4. The segment tree maintains both sums and squared sums.
5. Add the root's squared sum to the final answer.

TC: O(n log n)
SC: O(n)
*/