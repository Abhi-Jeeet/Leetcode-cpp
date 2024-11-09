class Solution {
public:
    int uniquePaths(int m, int n) {
        //optimized approach
        int N = m+n-2;
        int r = m-1;
        double res = 1;

        for(int i=1; i<=r; i++){
            res = res*(N-r+i)/i;
            
        }
        return res;
        
    }
};

//dp(Approach-2)

class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
        //base case
        if((i==m-1) && (j==n-1)){
            return 1;
        }
        
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }   

        int ans = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
        dp[i][j] = ans;
        return dp[i][j] ;   
        
            
        
    }
    int uniquePaths(int m, int n) {
        int i=0; 
        int j=0;
        //2d dp
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return countPaths(i, j, m, n, dp);
    }
};

