class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sortArray=arr;
        sort(sortArray.begin(), sortArray.end());

        unordered_map<int, int>map;
        int rank =1;
        for(auto it: sortArray){
            if(map.find(it) == map.end()){
                map[it]=rank++;
            }
        }
        vector<int>ans;
        for(auto it:arr){
            ans.push_back(map[it]);
        }
        return ans;
    }
};