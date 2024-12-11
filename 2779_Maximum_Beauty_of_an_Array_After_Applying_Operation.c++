class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int maxValue = 0;

        // Find the maximum value in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
            }
        }

        // Create an array to track ranges
        vector<int> range(maxValue + 10, 0);

        // Mark ranges for each number in the array
        for (int i = 0; i < n; i++) {
            int left = max(0, nums[i] - k);
            int right = min(maxValue, nums[i] + k) + 1;
            range[left]++;
            range[right]--;
        }

        // Calculate prefix sums and find the maximum value
        int result = range[0];
        for (int i = 1; i < range.size(); i++) {
            range[i] += range[i - 1];
            if (range[i] > result) {
                result = range[i];
            }
        }

        return result;
    }
};