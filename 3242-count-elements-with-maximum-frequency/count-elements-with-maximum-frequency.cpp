class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101, 0);
        int maxFreq = 0;

        for(int &num : nums) {
            count[num]++;
            maxFreq = max(maxFreq, count[num]);
        }
        int result = 0;

        for(int i = 0; i < 101; i++) {
            if(count[i] == maxFreq) {
                result += maxFreq;
            }
        }
        return result;
    }
};

/*
Approach: Frequency Array

1. Create an array to store the frequency of each number.
2. Traverse nums and update the frequencies.
3. Track the maximum frequency using maxFreq.
4. Traverse the frequency array again.
5. For every number whose frequency equals maxFreq,
   add maxFreq to the result.

TC: O(n + 101) = O(n)
SC: O(101) = O(1)
*/