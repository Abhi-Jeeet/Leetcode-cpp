class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int curr = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                maxSum = max(maxSum, curr);
                curr=0;
            }
            curr+=nums[i];
        }
        return max(maxSum, curr);
    }
};