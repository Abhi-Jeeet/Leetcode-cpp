//Recursion TLE
class Solution {
public:
    int recursion(int i, int j, vector<vector<int>>& obstacleGrid ){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;

        int up = recursion(i-1, j, obstacleGrid);
        int left = recursion(i, j-1, obstacleGrid);

        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        return recursion(n-1, m-1, obstacleGrid);
    }
};