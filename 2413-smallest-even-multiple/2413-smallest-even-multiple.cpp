class Solution {
public:
    int smallestEvenMultiple(int n) {
        int len = lcm(2,n);
        if(len != n){
            return 2*n;
        }
        return n;
    }
};