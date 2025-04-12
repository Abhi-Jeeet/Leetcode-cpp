class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> st;
            int d = (n + 1) >> 1;
            int low = pow(10, d - 1);
            int high = pow(10, d) - 1;
            vector<long long> factorial(n + 1, 1);
    
            for (int i = 1; i <= n; i++) {
                factorial[i] = factorial[i - 1] * i;
            }
    
            for (int i = low; i <= high; i++) {
                string left_half = to_string(i);
                string full;
                if (n % 2) {
                    string right_half = left_half.substr(0, d - 1);
                    reverse(right_half.begin(), right_half.end());
                    full = left_half + right_half;
                } else {
                    string right_half = left_half;
                    reverse(right_half.begin(), right_half.end());
                    full = left_half + right_half;
                }
                long long val = stoll(full);
                if (val % k) {
                    continue;
                }
                sort(full.begin(), full.end());
                st.insert(full);
            }
            
            long long result = 0;
            for (auto& s : st) {
                vector<int> count(10);
                for (auto ch : s) {
                    count[ch - '0']++;
                }
    
                int total_len = s.size();
                int zero_count = count[0];
    
                int nonzero_len = total_len - zero_count;
    
                long long permutation = nonzero_len * factorial[total_len - 1];
    
                for (auto x : count) {
                    permutation /= factorial[x];
                }
    
                result += permutation;
            }
    
            return result;
        }
    };