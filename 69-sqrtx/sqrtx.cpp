class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(1LL * mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
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