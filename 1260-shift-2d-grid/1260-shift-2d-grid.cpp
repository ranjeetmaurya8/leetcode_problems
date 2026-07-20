class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int> (n));

        int total = m*n;

        for(int i = 0; i<m ;i++){
            for(int j =0 ; j<n;j++){


                int index= i*n + j; //  0
                
                int newindex = (index + k) % total;// 1

                int newrow = newindex / n ;// 0
                int newcol = newindex % n ;// 1

                ans[newrow][newcol] = grid[i][j];
            }
        }
        return ans;
    }
};