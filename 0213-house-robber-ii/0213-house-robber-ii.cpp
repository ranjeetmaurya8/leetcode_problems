class Solution {
public:

int helper(vector<int>& nums , int st , int end ){
    int n = nums.size();



    vector<int> dp(n-1);
    dp[0] = nums[st];
    dp[1] = max(nums[st], nums[st+1]);

    for(int  i= st+2 , j= 2; i<=end ;i++, j++){
        dp[j] = max(dp[j-1] , dp[j-2]+nums[i]);
    }

    return dp[n-2];

}
    int rob(vector<int>& nums) {
        int n = nums.size();

        
     if(n == 1) return nums[0];
    if(n==2) return max(nums[0], nums[1]);

    return max(helper(nums , 0 , n-2) , helper(nums , 1 , n-1));
    
    }
};