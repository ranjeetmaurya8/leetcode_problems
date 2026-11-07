class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int clo_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - clo_sum)) {
                    clo_sum = sum;
                }

                if (sum < target) {
                    left++;

                }

                else if (sum > target) {
                    right--;

                } else {
                    return sum;
                }
            }
        }
        return clo_sum;
    }
};