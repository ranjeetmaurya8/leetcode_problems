class Solution {
public:
      bool ispalind(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s2 ==s;
              }


     void get_all_par( string s , vector<string> &partitions, vector<vector<string>> &ans ){
        // base case
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }



        for(int i =0 ; i<s.size();i++){
            string part = s.substr(0 , i+1);

            if(ispalind(part)){
             partitions.push_back(part);
             get_all_par(s.substr(i+1), partitions, ans);
             partitions.pop_back();// backtracking
            }

        }
     }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        get_all_par(s, partitions, ans);
        return ans;
    }
};