class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middleIndex = n / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == nums[middleIndex]) {
                count++;
            }
        }

        return count == 1;
    }
};