class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size();
            int m = moveTime[0].size();
    
            vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
            d[0][0][0] = 0;
    
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            pq.push({0, 0, 0, 0});
    
            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
            while (!pq.empty()) {
                vector<int> current = pq.top();
                pq.pop();
    
                int t = current[0];
                int i = current[1];
                int j = current[2];
                int p = current[3];
    
                if (t > d[i][j][p]) continue;
    
                for (auto dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        int nt = max(t, moveTime[ni][nj]) + (p == 0 ? 1 : 2);
                        if (nt < d[ni][nj][1 - p]) {
                            d[ni][nj][1 - p] = nt;
                            pq.push({nt, ni, nj, 1 - p});
                        }
                    }
                }
            }
    
            return min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
        }
    };