//Approach-1 (Square and sort and pick larger and smaller)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        sort(begin(nums), end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};

/*
Approach:
1. Square every element.
2. Sort the squared values.
3. Add the larger half of the values.
4. Subtract the sum of the smaller half.

TC: O(n log n)
SC: O(1) auxiliary space, excluding sorting stack space.
*/

/*----------------------------------------------------------------------------------------

//Approach-2 (Square and partial-sort and pick larger and smaller)
//T.C : Average O(n) because of nth_element
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        nth_element(begin(nums), begin(nums)+n/2, end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};



/*
Approach:
1. Square every element.
2. Use nth_element to partition the array around its middle.
3. Sum the larger partition and subtract the smaller partition.
4. Sorting is avoided, making the average time complexity O(n).

TC: Average O(n)
SC: O(1) auxiliary space.
*/

