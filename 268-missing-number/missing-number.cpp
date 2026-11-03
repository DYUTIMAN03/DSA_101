/*
Approach 1: Sorting + Linear Search
TC: O(n log n)
SC: O(1) auxiliary space (excluding sorting stack space)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // Expected value at index i is i
            if(nums[i] != i)
                return i;
        }

        // If all indices match, n is missing
        return n;
    }
};
*/


// Approach 2: Expected Sum - Actual Sum
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;

        for(int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};