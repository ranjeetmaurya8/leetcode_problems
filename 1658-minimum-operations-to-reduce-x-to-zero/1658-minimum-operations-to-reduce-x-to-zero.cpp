class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalsum += nums[i];
        }
        int target = totalsum - x;
        if (target < 0) {
            return -1;
        }

        int left = 0;
        int currsum = 0;
        int maxlen = -1;

        for (int right = 0; right < nums.size(); right++) {
            currsum += nums[right];

            while (currsum > target && left <= right) {
                currsum -= nums[left];
                left++;
            }

            if (currsum == target) {
                maxlen = max(maxlen,  right- left + 1);
            }
        }
        if (maxlen == -1) {
            return -1;
        }
        return nums.size() - maxlen;
    }
};