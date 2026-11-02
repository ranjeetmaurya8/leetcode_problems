class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int num  = x;
        long long reverse = 0;

        while(x > 0){
            int dig = x% 10;
            reverse = reverse*10 + dig;
            x= x/10;

        }

        return reverse == num;
    }
};