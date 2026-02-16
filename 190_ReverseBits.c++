class Solution {
public:
    int reverseBits(int n) {
        long long ans = 0;
        int count = 0;

        while(count < 32){
            ans = ans * 2 + (n & 1);
            n >>= 1;
            count++;
        }
        return ans;
    }
};