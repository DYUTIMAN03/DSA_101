/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int &x: arr){
            mp[x]++;
        }

        unordered_set<int> st;
        for(auto &it: mp){
            int freq = it.second;

            if(st.find(freq) != st.end()){
                return false;
            }
            else st.insert(freq);
        }
        return true;
    }
};
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);

        for(int &x: arr){
            vec[x+1000]++;
        }
        sort(vec.begin(), vec.end());

        for(int i=0; i<2001; i++){
            if(vec[i]!=0 && vec[i]==vec[i-1]) return false;
        }
        return true;
    }
};