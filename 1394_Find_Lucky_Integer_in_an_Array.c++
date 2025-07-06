class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(auto it: arr){
            mp[it]++;
        }
        for(const auto& [key, value]:mp){
            if(key==value){
                ans = max(ans, value);
            }
        }
        return ans;
    }
};