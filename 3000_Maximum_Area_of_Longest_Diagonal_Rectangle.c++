class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = -1;
        int maxArea = 0;
        int ans = INT_MIN;
        int n = dimensions.size();
        for(int i=0; i<n; i++){
            int first = dimensions[i][0];
            int second = dimensions[i][1];
            double diagonal = sqrt(first*first + second*second);
            int area = first*second;

            if(diagonal>maxDiagonal){
                maxDiagonal = diagonal;
                maxArea = area;
            }
            else if(diagonal == maxDiagonal){
                maxArea = max(maxArea,area);
            }
            
        }
        return maxArea;
        
    }
};