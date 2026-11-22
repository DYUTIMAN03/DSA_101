class Solution {
public:
    bool checkString(string s) {
        string ans = s;
        sort(ans.begin(), ans.end());

        return s == ans;
    }
};

//complexity O(logn)
// class Solution {
// public:
//     bool checkString(string s) {
//         bool seenB = false;
//         for(char ch: s){
//             if(ch == 'b'){
//                 seenB = true;
//             }
//             else if(seenB == true){
//                 return false;
//             }
//         }
//         return true;
//     }
// };