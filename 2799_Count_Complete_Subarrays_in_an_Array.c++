class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int count = 0;
            int n = nums.size();
            unordered_set<int> k;
            for (int i = 0; i < n; i++) {
                k.insert(nums[i]);
            }
            for (int i = 0; i < n; i++) {
                unordered_set<int> st;
                for (int j = i; j < n; j++) {
                    st.insert(nums[j]);
                    if (st.size() == k.size())
                        count++;
                }
            }
            return count;
        }
    };