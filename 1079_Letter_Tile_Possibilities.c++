class Solution {
    public:
        int numTilePossibilities(string tiles) {
            int n = tiles.size();
            vector<int> vis(n, 0);
            set<string> st;
            string res;
            helper(0, vis, tiles, res, st);
            return st.size() - 1;
        }
        void helper(int ind, vector<int>& vis, string tiles, string res,
                    set<string>& st) {
            st.insert(res);
            for (int i = 0; i < tiles.size(); i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    helper(ind + 1, vis, tiles, res + tiles[i], st);
                    vis[i] = 0;
                }
            }
        }
    };