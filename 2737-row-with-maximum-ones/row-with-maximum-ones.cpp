class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int max_count = 0;
        int row_index = 0;

        for(int row=0; row<n; row++){
            int count = 0;
            for(int col=0; col<m; col++){
                if(mat[row][col] == 1){
                    count++;
                }
            }
            if(count > max_count){
                max_count = max(max_count, count);
                row_index = row;
            }
        }
        return {row_index, max_count};
    }
};