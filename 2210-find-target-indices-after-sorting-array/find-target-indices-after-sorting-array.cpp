class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                result.push_back(i);
            }
        }

        return result;
    }
};

/*
Approach: Sorting + Traversal

1. Sort nums in ascending order.
2. Traverse the sorted array.
3. Whenever nums[i] == target, add index i to result.
4. Return result.

TC: O(n log n)
SC: O(1) auxiliary space, excluding result and sorting stack.
*/