class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();

        int i = n-2;
        //finding the larget index i which satisfy nums[i]<nums[i+1]
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }

        //if i exists, find the largest index j which satisfy nums[j]>nums[i]
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i +1, nums.end());
    }
};