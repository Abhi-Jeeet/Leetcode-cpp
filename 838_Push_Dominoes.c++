class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            vector<int> rightClosestL(n, -1);
            vector<int> leftClosestR(n, -1);
    
            // Track closest 'R' from the left
            int lastR = -1;
            for (int i = 0; i < n; ++i) {
                if (dominoes[i] == 'R') lastR = i;
                else if (dominoes[i] == 'L') lastR = -1;
                leftClosestR[i] = lastR;
            }
    
            // Track closest 'L' from the right
            int lastL = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (dominoes[i] == 'L') lastL = i;
                else if (dominoes[i] == 'R') lastL = -1;
                rightClosestL[i] = lastL;
            }
    
            string result(n, ' ');
            for (int i = 0; i < n; ++i) {
                if (dominoes[i] != '.') {
                    result[i] = dominoes[i];
                    continue;
                }
    
                int distR = leftClosestR[i] == -1 ? INT_MAX : i - leftClosestR[i];
                int distL = rightClosestL[i] == -1 ? INT_MAX : rightClosestL[i] - i;
    
                if (distR == distL) result[i] = '.';
                else if (distR < distL) result[i] = 'R';
                else result[i] = 'L';
            }
    
            return result;
        }
    };
    