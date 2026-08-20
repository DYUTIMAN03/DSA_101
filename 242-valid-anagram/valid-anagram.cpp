// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         if(s==t){
//             return true;
//         }
//         return false;
        
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.length();
        int m = t.length();
        if (n != m){
            return false;
        }
        //int count[26] = {0};
        vector<int> count(26, 0);

        for (int i=0; i<n; i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i=0; i<count.size(); i++){ //i<26 krna is case p
            if(count[i] != 0){
                return false;
            }
       
        }
        return true;
    }
    
};