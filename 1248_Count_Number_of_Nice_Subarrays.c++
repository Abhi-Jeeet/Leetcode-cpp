class Solution {
public:
    int noOfArray(vector<int>& nums, int k){
        int n = nums.size();
        int left=0;
        int right=0;
        int count=0;
        int sum=0;

        if(k<0) return 0;
        while(right<n){
            sum+=nums[right]%2;
            while(sum>k){
                sum-=nums[left]%2;
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (noOfArray(nums,k) - noOfArray(nums,k-1));
    }
};