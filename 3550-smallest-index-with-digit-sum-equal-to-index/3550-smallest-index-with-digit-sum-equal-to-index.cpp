class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int dig = nums[i];

            int sum = 0;

            while (dig > 0) {
                int  digit = dig % 10;
                sum = sum + digit;
                dig = dig / 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};