class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength=0;
        int right=0;
        int left=0;
        int zeroCount=0;
        int n = nums.size();
        while(right<n){
            if(nums[right]==0){
                zeroCount++;
            }
            while(zeroCount>1){
                if(nums[left]==0){
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right-left+1);



            right++;
        }
        return maxLength-1;

    }
};