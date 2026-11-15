class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(1LL*mid*mid <= x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};

/*
APPROACH:
1. Search for the largest integer whose square is <= x.
2. If mid * mid <= x, save mid and search right.
3. Otherwise, search left.
4. Return the last valid answer.

TC: O(log x)
SC: O(1)
*/

// class Solution {
// public:
//     int mySqrt(int x) {
//         int i = 0;
//         while(1LL * (i + 1) * (i + 1) <= x) {
//             i++;
//         }
//         return i;
//     }
// };

/*
APPROACH:
1. Start i from 0.
2. Check whether (i+1) * (i+1) <= x.
3. If true, increment i.
4. If false, return i.

TC: O(sqrt(x))
SC: O(1)
*/