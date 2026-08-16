class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {

        int n = nums.size();

        int maxRight = -1;
        
        for(int i=n-1; i>=0; i--){
            int current = nums[i];
            nums[i] = maxRight;
            maxRight = max(maxRight,current);
        }
        return nums;    
    }
};