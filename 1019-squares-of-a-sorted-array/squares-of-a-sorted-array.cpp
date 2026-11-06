/*
APPROACH 1: Square + Sort
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            nums[i] = nums[i] * nums[i];
        sort(nums.begin(), nums.end());
        return nums;
    }
};
TC: O(n log n)
SC: O(1) auxiliary space (excluding sorting stack space).


APPROACH 2: Two Pointers
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int i = 0, j = n-1, k = n-1;
        while(k >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if(a > b) {
                result[k] = a;
                i++;
            } else {
                result[k] = b;
                j--;
            }
            k--;
        }
        return result;
    }
};

/*
APPROACH 1:
1. Square every element.
2. Sort the squared elements.
3. Return the modified array.

TC: O(n log n)
SC: O(1) auxiliary space (excluding sorting stack space).


APPROACH 2:
1. Place i at the beginning and j at the end.
2. Compare the squares of both elements.
3. Place the larger square at result[k].
4. Move the corresponding pointer.
5. Decrease k and repeat until the result is filled.

TC: O(n)
SC: O(n), for the result array.
*/