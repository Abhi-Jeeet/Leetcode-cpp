class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_set<int>on;
        for(int it: bulbs){
            if(on.count(it)) on.erase(it);
            else on.insert(it);
        }
        vector<int>ans(on.begin(), on.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};