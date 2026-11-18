class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};
/*
APPROACH:
1. Initialize low = 0 and high = n-1.
2. Calculate mid.
3. If nums[mid] == target, return mid.
4. If nums[mid] < target, search the right half.
5. If nums[mid] > target, search the left half.
6. If the target isn't found, return low.
   low represents the correct insertion position.

TC: O(log n)
SC: O(1)
*/

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             if(nums[i] >= target) {
//                 return i;
//             }
//         }

//         return n;
//     }
// };

/*
APPROACH:
1. Traverse the sorted array.
2. Find the first element >= target.
3. Return its index.
4. If no element is >= target, return n.

TC: O(n)
SC: O(1)
*/