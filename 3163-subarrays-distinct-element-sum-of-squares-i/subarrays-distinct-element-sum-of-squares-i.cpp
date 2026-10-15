class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);

                result += st.size() * st.size();
            }
        }
        return result;
    }
};


/*
Approach: Brute Force + Set

1. Fix the starting index i.
2. Extend the ending index j to generate every subarray.
3. Store each subarray's elements in a set to maintain distinct values.
4. Square the set's size and add it to result.

TC: O(n^2 log n)
SC: O(n)
*/