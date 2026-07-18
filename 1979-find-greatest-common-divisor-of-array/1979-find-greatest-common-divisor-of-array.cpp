class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int ans;
        int smallest = nums[0];
        int greatest = nums[0];
        for(int i =1 ; i<n ;i++){
            if(nums[i] < smallest){
             smallest = nums[i];
        
            }
            if(nums[i]> greatest){
                greatest = nums[i];
            }
            ans  = gcd(smallest, greatest);
        }
        return ans;
    }
};