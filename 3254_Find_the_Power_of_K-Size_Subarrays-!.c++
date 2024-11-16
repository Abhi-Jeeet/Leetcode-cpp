class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> results;
        int n=nums.size();
        for(int i=0; i<=n-k; i++){
            bool isValid=true;
            for(int j=i; j<i+k-1; j++){
                if(nums[j+1]!= nums[j]+1){
                    isValid=false;
                    break;
                }
            }
            if(isValid){
                results.push_back(nums[i+k-1]);
            }
            else{
                
                results.push_back(-1);
            }

            
        }
        return results;
    }
};