class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        int n = row * col;

        k %= n;
        if (k == 0)
            return grid;

        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / col][i % col], grid[j / col][j % col]);
                i++;
                j--;
            }
        };
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);

        return grid;
    }
};


/*
// take extra space
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> temp(m,vector<int>(n,0)); // create m*n matrix with all value = 0
        for(int row = 0;  row < m; row++){
            for(int col = 0; col < n; col++){
                // formula to find index of that new value in matrix
                int new_val = ((row * n + col) + k) %  (m*n); // % m*n prevent overflow
                int new_row = new_val / n; // to find row
                int new_col = new_val % n; // to find coloumn
                temp[new_row][new_col] = grid[row][col];
            }
        }
        return temp;
    }
};
*/