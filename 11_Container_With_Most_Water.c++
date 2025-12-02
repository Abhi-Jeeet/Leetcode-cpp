class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxi =0;
        while(left<right){
            int width = right-left;
            int minH = min(height[right], height[left]);
            int area = width*minH;
            maxi = max(maxi, area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};