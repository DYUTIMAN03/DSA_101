class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int largest = 0;
        int sec_largest = 0;

        for(int &x: nums){
            if(x>largest){
                sec_largest = largest;
                largest = x;
            }
            else sec_largest = max(sec_largest, x);
        }
        return (largest - 1) * (sec_largest - 1);
    }
};