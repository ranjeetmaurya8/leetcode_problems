class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;

        for (int ch : s) {
            if (ch == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    ans++;
                }
            }
        }
        return ans + balance;
        ;
    }
};