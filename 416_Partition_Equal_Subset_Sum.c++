class Solution {
    public:
        bool recursion(int index, vector<int>& nums, int target, int sum, vector<vector<int>>& dp){
            if(index >= nums.size())return false;
            if(sum>target)return false;
            if(sum==target)return true;
    
            if(dp[index][sum]!= -1)return dp[index][sum];
                    
            
            bool take =  recursion(index+1, nums, target, sum + nums[index], dp);
            bool notTake = recursion(index+1, nums, target, sum, dp);
    
            return dp[index][sum] = take || notTake;
            
    
        }
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if(sum%2!=0)return false;        
            int target = sum/2;  
            int currSum=0; 
    
            vector<vector<int>>dp(n, vector<int>(target+1, -1));  
    
            return recursion(0,nums, target, currSum, dp);
    
        }
    };