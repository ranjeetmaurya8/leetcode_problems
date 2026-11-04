class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans ;
        unordered_set<int> s;
        int a, b;
        int n = grid.size();
        int   expected_sum =0  ;
        int actual_sum=0;

        for(int i =0 ; i<n ; i++){
            for(int j = 0; j<n ;j++){
                actual_sum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);

                }

                s.insert(grid[i][j]);
            }
        }

        expected_sum = ((n * n)*(n * n + 1))/2;
        b = expected_sum + a - actual_sum;
        ans.push_back(b);

        return ans ;
    }
};