class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        int sum=0;
        unordered_map<int, int> mp;
        mp.insert({0,-1});

        for(int i=0; i<nums,size();i++){
            sum+=nums[i]==1 ? 1: -1;
            auto it=mp.find(sum);
            if(it!=mp.end()){
                ans=max(ans, i-it->second);
            }
            else{
                mp.insert({sum,i});
            }
        }
        return ans;
    }
};