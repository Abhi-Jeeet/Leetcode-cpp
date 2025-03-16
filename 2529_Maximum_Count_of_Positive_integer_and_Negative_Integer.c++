class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int negativeCount=0;
            int positiveCount=0;
            int ans=0;
    
            for(int i=0; i<nums.size(); i++){
                if(nums[i]<0){
                    negativeCount++;
                }
                else if(nums[i]==0){
                    continue;
                }
                else{
                    positiveCount++;
                }
            }
            ans = max(positiveCount, negativeCount);
            return ans;
    
        }
    };