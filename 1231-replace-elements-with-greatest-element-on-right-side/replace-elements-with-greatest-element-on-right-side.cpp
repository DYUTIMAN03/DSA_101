// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& nums) {

//         int n = nums.size();

//         int maxRight = -1;
        
//         for(int i=n-1; i>=0; i--){
//             int current = nums[i];
//             nums[i] = maxRight;
//             maxRight = max(maxRight,current);
//         }
//         return nums;    
//     }
// };

class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();

        int maxRight = -1;
        
        for(int i=n-1; i>=0; i--){
            int current = nums[i];
            ans.push_back(maxRight);
            maxRight = max(maxRight,current);
        }
        reverse(ans.begin(), ans.end());
        return ans;    
    }
};