class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int maxElement = *max_element(nums.begin(), nums.end());
            long long ans=0, start=0;
            int maxCount =0;
    
            for(int i=0; i<n; i++){
                if(nums[i]==maxElement){
                    maxCount++;
                }
                while(maxCount==k){
                    if(nums[start] == maxElement){
                        maxCount--;
                    }
                    start++;
                }
                ans+=start;
            }
            return ans;
        }
    };