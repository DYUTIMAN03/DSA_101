class Solution {
public:
    // Calculate the sum of digits
    int digitSum(int x) {
        int sum = 0;

        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> arr;

        // Store {digit sum, number}
        for(int x : nums) {
            arr.push_back({digitSum(x), x});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());

        // Map each number to its target index
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int result = 0;

        // Find cycles in the current arrangement
        for(int i = 0; i < n; i++) {
            if(visited[i] || mp[nums[i]] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while(!visited[j]) {
                visited[j] = true;
                j = mp[nums[j]];
                cycleSize++;
            }

            // A cycle of size k needs k-1 swaps
            result += cycleSize - 1;
        }

        return result;
    }
};

/*
Approach: Sorting + Cycle Detection

1. Calculate the digit sum of every number.
2. Sort by digit sum, then by numeric value.
3. Map every number to its target index.
4. Follow the positions to find cycles.
5. A cycle containing k elements needs k-1 swaps.

TC: O(n log n)
SC: O(n)
*/