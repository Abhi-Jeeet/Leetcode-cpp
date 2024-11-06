class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(auto interval: intervals){
            if(ans.empty()){
                ans.push_back(interval);
            }
            else if(interval[0] > ans.back()[1]){
                ans.push_back(interval);
            }
            else{
                vector<int> prevInterval = ans.back();
                ans.pop_back();
                ans.push_back({prevInterval[0], max(prevInterval[1],interval[1])});
            }
        }
        return ans;
    }
};