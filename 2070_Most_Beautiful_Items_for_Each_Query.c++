class Solution {
public:
    int binarySearch(vector<vector<int>>& items, int& query){
        int start = 0;
        int end = items.size()-1;
        int maxBeauty =0;

        while(start<=end){
            int mid = start + (end - start)/2;
            if(items[mid][0] > query){
                end = mid-1; //left ki traf move krna hai
            }
            else{
                maxBeauty = max(maxBeauty, items[mid][1]);
                //right ki traf move kr jao
                start = mid+1;
            }
        }
        return maxBeauty;

    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n =items.size();
        int m = queries.size();

        vector<int>ans(m);

        sort(items.begin(), items.end());

        int beauty = items[0][1];
        for(int i=0; i<n; i++){
            beauty = max(beauty, items[i][1]);
            items[i][1]=beauty;
        }

        for(int i=0; i<m; i++){
            int query = queries[i];
            ans[i] = binarySearch(items, query);
        }
        return ans;
    }
};