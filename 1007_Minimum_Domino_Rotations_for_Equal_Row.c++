class Solution {
    public:
        int check(int x, vector<int>& tops, vector<int>& bottoms) {
            int rotation_top = 0, rotation_bottom = 0;
            for (int i = 0; i < tops.size(); ++i) {
                if (tops[i] != x && bottoms[i] != x)
                    return -1; 
                else if (tops[i] != x)
                    rotation_top++; 
                else if (bottoms[i] != x)
                    rotation_bottom++; 
            }
            return min(rotation_top, rotation_bottom);
        }
    
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int result = check(tops[0], tops, bottoms);
            if (result != -1 || tops[0] == bottoms[0])
                return result;
            else
                return check(bottoms[0], tops, bottoms);
        }
    };
    