class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for (int i = low; i <= high; i++) {
                string x = to_string(i);
                int length = x.size();
    
                if (length % 2 == 0) {
                    int half = length / 2;
                    int sum1 = 0, sum2 = 0;
    
                    for (int j = 0; j < half; j++) {
                        sum1 += x[j] - '0';
                    }
                    for (int j = half; j < length; j++) {
                        sum2 += x[j] - '0';
                    }
    
                    if (sum1 == sum2) {
                        count++;
                    }
                }
            }
            return count;
        }
    };
    