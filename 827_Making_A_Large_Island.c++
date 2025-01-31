class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col, int n, int id, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        grid[row][col] = id;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int cnt = 1;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = id;
                    q.push({nrow, ncol});
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = 0;
        int id = 2;
        unordered_map<int, int> mp;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cnt = bfs(grid, i, j, n, id, vis);
                    mp[id] = cnt;
                    maxi = max(maxi, cnt);
                    id++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    for (int d = 0; d < 4; d++) {
                        int nrow = i + delrow[d];
                        int ncol = j + delcol[d];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] > 1) {
                            uniqueIslands.insert(grid[nrow][ncol]);
                        }
                    }
                    
                    int newSize = 1;
                    for (int islandId : uniqueIslands) {
                        newSize += mp[islandId];
                    }
                    maxi = max(maxi, newSize);
                }
            }
        }
        
        return maxi;
    }
};