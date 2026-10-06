/*
class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n = words.size();
        unordered_map<char, int> mp;

        for(auto &word: words){
            for(auto &ch: word){
                mp[ch]++;
            }
        }
        for(auto &it: mp){
            int freq = it.second;
            if(freq % n != 0) return false;
        }
        return true;
    }
};
*/

/*
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count[26] = {0};
        int n = words.size();
        for(string &word : words) {
            for(char &ch : word) {
                count[ch - 'a']++;
            }
        }
        for(int &freq : count) {
            if(freq % n != 0)
                return false;
        }
        return true;
    }
};
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int count[26] = {0};

        for(string &word : words) {
            for(char &ch : word) {
                count[ch - 'a']++;
            }
        }

        auto lambda = [&](int freq){
            return freq % n == 0;
        };
        return all_of(begin(count), end(count), lambda);
    }
};