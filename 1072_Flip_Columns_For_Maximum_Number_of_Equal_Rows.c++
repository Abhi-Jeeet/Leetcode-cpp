class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> mp;  

        // Convert each row to a canonical form and count occurrences
        for (auto row : matrix) {
            int first = row[0];
            string canonical = "";
            for (int i = 0; i < row.size(); i++) {
                canonical += (first == row[i]) ? '1' : '0';
            }
            mp[canonical]++;  // Increment the count of this pattern
        }

        int mx = 0;
        // Find the maximum count of any row pattern
        for (auto val : mp) {
            mx = max(val.second, mx);
        }
        return mx; 
    }
};