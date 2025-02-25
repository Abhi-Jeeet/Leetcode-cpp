const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1; 
        int sum = 0, count = 0;

        for (int num : arr) {
            sum = (sum + num) % 2;  

            if (sum == 0) {
                count = (count + odd) % MOD;
                even++;
            } else {
                count = (count + even) % MOD;
                odd++;
            }
        }

        return count;
    }
};
