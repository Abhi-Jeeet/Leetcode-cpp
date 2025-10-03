class Solution {
public:
    //T.C -> O(nlogn)
    //S.C -> O(n)
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        set<int>st;

        for(int i=0; i<n; i++){
            if(nums[i]>0) st.insert(nums[i]);
        }
        return st.size();
    }
};