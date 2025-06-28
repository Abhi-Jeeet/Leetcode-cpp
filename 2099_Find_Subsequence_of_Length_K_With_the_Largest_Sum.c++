class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> original = nums;
        sort(original.begin(), original.end(), greater<int>());  

        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[original[i]]++;  
        }

        vector<int> ans;
        for (int num : nums) {
            if (freq[num] > 0) {
                ans.push_back(num);
                freq[num]--;
            }
        }

        return ans;
    }
};
