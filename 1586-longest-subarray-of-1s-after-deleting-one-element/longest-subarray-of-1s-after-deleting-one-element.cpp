//brute force
/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int zeroCount = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zeroCount++;
                }
                if (zeroCount > 1) {
                    break;
                }
                // Delete one element, so length is window size - 1
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};
*/

//sliding window

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int maxLength = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0)
                zeroCount++;

            while (zeroCount > 1) {
                if (nums[i] == 0)
                    zeroCount--;

                i++;
            }

            maxLength = max(maxLength, j - i);
        }

        return maxLength;
    }
};