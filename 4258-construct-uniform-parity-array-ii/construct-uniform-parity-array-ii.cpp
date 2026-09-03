class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minimum = INT_MAX;

        // Find smallest odd number
        for(int x: nums1){
            if(x % 2 == 1){
                minimum = min(minimum, x);
            }
        }
         // Find smallest even number
        for(int x: nums1){
            if(x % 2 == 0 && minimum != INT_MAX && x < minimum){
                return false;
            }
        }
        return true;
    }
};