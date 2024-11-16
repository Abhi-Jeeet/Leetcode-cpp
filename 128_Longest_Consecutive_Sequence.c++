//Better Approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int lastSmaller = INT_MIN;
        int longest =1;

        if(nums.size()==0) return 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmaller){
                count++;
                lastSmaller = nums[i];
            }
            else if( lastSmaller != nums[i]){
                count =1;
                lastSmaller = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;


    }
};