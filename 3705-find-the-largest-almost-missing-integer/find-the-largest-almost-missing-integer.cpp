class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k==n){
            return *max_element(nums.begin(), nums.end());
        }
        
        if(k==1){
            unordered_map<int,int>mp;
            for(int val:nums){
                mp[val]++;
            }
            int ans= -1;
            for(auto it:mp){
                if(it.second == 1){
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }
        int start = nums[0];
        int end = nums[n-1];

        if(start==end) return -1;

        for(int i=1; i<n-1; i++){
            if(nums[i]==start) start = -1;
            if(nums[i]==end) end = -1;
        }
        return max(start,end);
    }
};
