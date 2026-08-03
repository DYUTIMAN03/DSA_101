class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();

        int maxOnes = 0;
        int countOnes = 0;
        int maxZeros = 0;
        int countZeros = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                countOnes++;
                maxOnes = max(maxOnes, countOnes);
            }
            else countOnes = 0;

            if(s[i] == '0'){
                countZeros++; 
                maxZeros = max(maxZeros, countZeros);           
            }
            else countZeros = 0;
        }
        return maxOnes > maxZeros;    
    }
};