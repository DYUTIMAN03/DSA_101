// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(nums1[i] == nums2[j]) return nums1[i];
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};

/*
Approach: Two Pointers

1. Start both pointers at index 0.
2. If elements match, return the common value.
3. If nums1[i] is smaller, increment i.
4. Otherwise, increment j.
5. If either array ends, return -1.

TC: O(n + m)
SC: O(1)
*/