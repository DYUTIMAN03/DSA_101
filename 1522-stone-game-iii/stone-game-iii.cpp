class Solution {
public:
    int n;
    vector<int>dp;

    int solve(vector<int>& stones, int i){
        if (i > n-1) return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        int result;
        result = stones[i] - solve(stones,i+1);
        if(i+1<n)
            result = max(result, stones[i] + stones[i+1] - solve(stones,i+2));
        if(i+2<n)
            result = max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones,i+3));
        return dp[i] = result;
    }

    string stoneGameIII(vector<int>& stones){
        n = stones.size();
        dp.resize(n+1, -1);

        int difference = solve(stones, 0);   //here 0 is index not value

        if (difference > 0) return "Alice";
        if (difference < 0) return "Bob";
        else return "Tie";

        
    }
};