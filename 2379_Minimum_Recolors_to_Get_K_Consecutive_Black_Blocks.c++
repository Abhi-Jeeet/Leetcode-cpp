class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int whiteCount = 0;
            // Count white blocks in the first window of size k
            for(int i = 0; i < k; i++) {
                if(blocks[i] == 'W') whiteCount++;
            }
            int minWhite = whiteCount;
            
            // Slide the window through the rest of the string
            for(int i = k; i < blocks.size(); i++) {
                if(blocks[i] == 'W') whiteCount++; // add new block
                if(blocks[i - k] == 'W') whiteCount--; // remove old block
                minWhite = min(minWhite, whiteCount);
            }
            
            return minWhite;
        }
    };