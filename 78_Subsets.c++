class Solution {
    public:
        void solve(vector<int> nums, vector<vector<int>>& ans, vector<int> output,
                   int n, int index) {
            // base case
            if (index >= n) {
                ans.push_back(output);
                return;
            }
            // exclude
            solve(nums, ans, output, n, index + 1);
            // include
            int element = nums[index];
            output.push_back(element);
            solve(nums, ans, output, n, index + 1);
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> output;
            int n = nums.size();
            int index = 0;
    
            solve(nums, ans, output, n, index);
            return ans;
        }
    };