class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n = nums.size();
        long long ans = 0;

        int minPosition = -1;
        int maxPosition = -1;
        int culpritIndex = -1;

        for(int i=0; i<n; i++){
            if(nums[i]>maxK || nums[i]<minK) culpritIndex = i;
            if(nums[i]==maxK) maxPosition = i;
            if(nums[i]==minK) minPosition = i;


            long long smaller = min(minPosition, maxPosition);
            long long temp = smaller - culpritIndex;
            ans += (temp<=0) ? 0 : temp;
        }
        return ans;
    }
};