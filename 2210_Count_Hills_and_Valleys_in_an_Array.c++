class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        vector<int>filter;
        filter.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                filter.push_back(nums[i]);
            }
        }
        for(int i=1; i<filter.size()-1; i++){
            if(filter[i]>filter[i+1] && filter[i]> filter[i-1])count++;
            if(filter[i]<filter[i+1] && filter[i]< filter[i-1])count++;
            
        }
        return count;
        
    }
};