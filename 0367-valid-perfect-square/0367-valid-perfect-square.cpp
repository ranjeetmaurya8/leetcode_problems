class Solution {
public:
    bool isPerfectSquare(int num) {
        int ans = sqrt(num);
        return ans*ans == num;
    }
};