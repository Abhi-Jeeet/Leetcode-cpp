class Solution {
    public:
        int maxArraySum(vector<int>& nums){
            int maxi = INT_MIN;
            int sum =0;
            for(int i=0; i<nums.size(); i++){
                sum+=nums[i];
                if(sum>maxi){
                    maxi = sum;
                }
                if(sum<0){
                    sum=0;
                }
            }
            return maxi;
        }
    
        int minArraySum(vector<int>& nums){
            int mini = INT_MAX;
            int sum =0;
            for(int i=0; i<nums.size(); i++){
                sum+=nums[i];
                if(sum < mini){
                    mini = sum;
                }
                if(sum>0){
                    sum=0;
                }
            }
            return mini;
        }
        int maxAbsoluteSum(vector<int>& nums) {
            int a = maxArraySum(nums);
            int b = minArraySum(nums);
            return max(abs(a), abs(b));
        }
    };