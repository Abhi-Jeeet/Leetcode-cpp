class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }
        }

        //sorting
        reverse(negative.begin(), negative.end());

        for(auto it:negative){
            positive.push_back(it);
        }
        vector<int>ans;
        
        int i=0;
        int j=positive.size()-1;
        while(i<j){
            ans.push_back(positive[i]);
            i++;
            ans.push_back(positive[j]);
            j--;
        }
        return ans;
        
        
        
    }
};