class Solution {
public:
    int MOD = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        unordered_map<int, long long> mp;
        mp[arr[0]] = 1; // Single-node tree

        for(int i = 1; i < n; i++) {
            long long count = 1; // Tree with arr[i] as root only

            for(int j = 0; j < i; j++) {
                int v = arr[j];

                // Check whether v and arr[i]/v can form the children
                if(arr[i] % v == 0 &&
                   mp.find(arr[i] / v) != mp.end()) {

                    // Left subtree ways * right subtree ways
                    count = (count + mp[v] * mp[arr[i] / v]) % MOD;
                }
            }
            mp[arr[i]] = count; // Store trees possible with arr[i] as root
        }
        int result = 0;
        // Add the number of trees possible for every value
        for(auto &it : mp) {
            result = (result + it.second) % MOD;
        }
        return result;
    }
};

/*
Approach:
1. Sort the array so smaller factors are processed first.
2. mp[x] stores the number of binary trees with x as the root.
3. Initialize count = 1 because x can form a single-node tree.
4. Try every smaller value v as one child.
5. If x % v == 0 and x/v exists in the map:
   ways = mp[v] * mp[x/v].
6. Add these ways to count and store mp[x].
7. Sum the counts for all array values.

TC: O(n^2) average
SC: O(n)

Note: Apply MOD during DP calculations to prevent overflow.
*/