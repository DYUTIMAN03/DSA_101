class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count1 = 0;
        int count2 = 0;

        for(int i=0; i<n; i++){
            if(s[i] != (i%2==0 ? '0' : '1')) count1++;   //010101010
            if(s[i] != (i%2==0 ? '1' : '0')) count2++;   //101010101
        }
        return min(count1, count2);
    }
};

