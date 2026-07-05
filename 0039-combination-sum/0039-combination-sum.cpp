class Solution {
public:
    //    set<vector<int>> s;
      void helper(vector<int> &arr, int i , int tar,vector<int> &combination, vector<vector<int>> &ans ){
        // base cases
         if(tar ==0){
            // if(s.find(combination) == s.end())
            ans.push_back({combination});
            // s.insert(combination);
            return;

        }

        int n = arr.size();
        if(tar <0 || i== n ){
            return;
        }




        combination.push_back(arr[i]);
       //helper(arr, i+1 ,tar-arr[i], combination, ans);  // single time  inclusion
        helper(arr, i , tar-arr[i], combination, ans);   // multiple time inclusion
         // backtracking
         combination.pop_back();
         helper(arr, i+1 , tar,combination ,ans);// exclusion

      }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combination;

        helper(arr, 0 , tar, combination,ans);

        return ans;

        
    }
};