class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>mp;
        for (int val: nums){
            mp[val]++;
            if(mp[val]>1){
                return true;
            }
        }
    return false;    
    }    
};