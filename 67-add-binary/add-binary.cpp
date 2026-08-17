class Solution {
public:
    string addBinary(string a, string b) {

        int n = a.length();
        int m = b.length();
        int carry = 0;
        
        string ans = "";

        int i = n-1;
        int j = m-1;

        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0){
                sum = sum + a[i] - '0';
                i--;
            }
            if(j>=0){
                sum = sum + b[j] - '0';
                j--;
            }
            int bit = sum % 2;
            ans += bit + '0';

            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};