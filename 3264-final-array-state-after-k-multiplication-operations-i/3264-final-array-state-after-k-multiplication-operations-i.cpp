class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       
        while(k>0){
            int idx  = 0 ;
            for(int i =1 ; i<nums.size(); i++){
                if(nums[i] < nums[idx]){
                    idx = i;
                }
            }
            nums[idx] *= multiplier;            
            k--;
        }
        return nums;
       
    }
};