class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>>ans(n, vector<int>(m,0));
        vector<vector<int>>vis(n, vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]==1){
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            ans[row][col]=step;
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow>=0 && newRow<n && newCol<m && newCol>=0 && vis[newRow][newCol]==0){
                    q.push({{newRow,newCol},step+1});
                    vis[newRow][newCol]=1;
                }
            }

        }
        return ans;
    }
};