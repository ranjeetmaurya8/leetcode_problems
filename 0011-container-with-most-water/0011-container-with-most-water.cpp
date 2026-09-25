class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int n = height.size();

        int i = 0;
        int j = n - 1;

        while(i<j){
            int w = j-i;
            int h = min(height[i], height[j]);

            int currwater  = w * h;

            maxwater  = max(currwater  , maxwater);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxwater;
    }
};