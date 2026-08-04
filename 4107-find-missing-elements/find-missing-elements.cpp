// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         int maxi = INT_MIN;
//         int mini = INT_MAX;

//         for(int val: nums){
//             mp.insert({val,1});
//             maxi = max(maxi,val);
//             mini = min(mini,val);
//         }
//         vector<int> ans;
        
//         for(int i = mini; i <= maxi; i++){
//             if(mp.find(i) == mp.end()){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int maximum = INT_MIN;
        int minimum = INT_MAX;

        for(int val: nums){
            mp.insert({val, 1});
            maximum = max(maximum, val);
            minimum = min(minimum, val);
        }
        vector<int> ans;
        for(int i=minimum; i<=maximum; i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};