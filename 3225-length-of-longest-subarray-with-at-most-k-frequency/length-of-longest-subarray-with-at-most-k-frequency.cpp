#include <vector>
#include <unordered_map>
#include <algorithm> // For std::max

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        // Map to store frequencies of elements in the current window
        std::unordered_map<int, int> freq;
        int maxLength = 0; // Stores the maximum length of a good subarray found
        int left = 0;      // Left pointer of the sliding window

        // Iterate with the right pointer to expand the window
        for (int right = 0; right < nums.size(); ++right) {
            // Add the current element to the window and update its frequency
            freq[nums[right]]++;

            // If the frequency of the current element (or any element in the window)
            // exceeds k, shrink the window from the left until it becomes good
            while (freq[nums[right]] > k) {
                // Decrement the frequency of the element at the left pointer
                freq[nums[left]]--;
                // Move the left pointer to the right
                left++;
            }

            // At this point, the window [left, right] is good.
            // Calculate its length and update maxLength if it's greater.
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};