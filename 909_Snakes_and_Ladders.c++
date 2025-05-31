class Solution {
public:
    int n;

    pair<int,int> getCoord(int num){
        int RT = (num - 1) / n;
        int RB = (n - 1) - RT;

        int col = (num - 1) % n;
        if ((n % 2 == 1 && RB % 2 == 1) || (n % 2 == 0 && RB % 2 == 0)) {
            col = (n - 1) - col;
        }
        return make_pair(RB, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size(); // Set the class member n
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n - 1][0] = true;
        q.push(1);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front();
                q.pop();
                if (x == n * n) return steps;

                for (int k = 1; k <= 6; k++) {
                    int val = x + k;
                    if (val > n * n) break;

                    auto [r, c] = getCoord(val);
                    if (vis[r][c]) continue;
                    vis[r][c] = true;

                    if (board[r][c] == -1) {
                        q.push(val);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
