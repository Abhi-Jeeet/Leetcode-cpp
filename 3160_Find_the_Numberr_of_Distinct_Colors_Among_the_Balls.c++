class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> cAmount;
        unordered_map<int,int> iColor;

        vector<int> res;

        int ongoing = 0;

        for (int i = 0;i<queries.size();i++) {

            if (cAmount[iColor[queries[i][0]]]==1) {
                ongoing--;
            }

            cAmount[iColor[queries[i][0]]]--;

            
            iColor[queries[i][0]] = queries[i][1];

            

            cAmount[iColor[queries[i][0]]]++;

            if (cAmount[iColor[queries[i][0]]]==1) {
                ongoing++;
            }


            res.push_back(ongoing);
        }

        return res;
    }
};