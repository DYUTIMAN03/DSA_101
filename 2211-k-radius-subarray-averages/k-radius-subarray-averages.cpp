// class Solution {
// public:
//     vector<int> getAverages(vector<int>& nums, int k) {
//         int n = nums.size();

//         if(k==0){
//             return nums;
//         }

//         vector<int> result(n,-1);

//         if(n < 2*k+1){
//             return result;
//         }

//         vector<long long> prefixSum(n,0);
//         prefixSum[0] = nums[0];

//         for(int i=1; i<n; i++){
//             prefixSum[i] = prefixSum[i-1] + nums[i];
//         }

//         for(int i=k; i <= n-k-1; i++){
//             int left_idx = i-k;
//             int right_idx = i+k;

//             long long sum = prefixSum[right_idx];
//             if(left_idx > 0) sum -= prefixSum[left_idx - 1];

//             result[i] = sum/(2*k+1);
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 0)
            return nums;

        vector<int> result(n, -1);

        if (n < 2 * k + 1)
            return result;

        long long window = 0;

        int left = 0;
        int right = 2 * k;
        int i = k;

        for (int j = left; j <= right; j++) {
            window += nums[j];
        }

        result[i] = window / (2 * k + 1);

        i++;
        right++;

        while (right < n) {
            int out_of_window = nums[left];
            int came_to_window = nums[right];

            window = window + came_to_window - out_of_window;

            result[i] = window / (2 * k + 1);

            i++;
            right++;
            left++;
        }
        return result;
    }
};