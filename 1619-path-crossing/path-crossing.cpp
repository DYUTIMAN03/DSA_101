class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;

        int x = 0;
        int y = 0;

        string key = to_string(x) + "," + to_string(y);
        st.insert(key);

        for(auto &ch: path){
            if(ch=='E') x++;
            else if(ch=='W') x--;
            else if(ch=='N') y++;
            else y--;

            string key = to_string(x) + "," + to_string(y);

            if(st.find(key)!=st.end()) return true;
            else st.insert(key);
        }
        return false;
    }
};