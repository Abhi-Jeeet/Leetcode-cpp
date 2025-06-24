class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>store;
        vector<int>ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==key){
                store.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<store.size(); j++){
                if(abs(i-store[j])<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
        
        
    }
};