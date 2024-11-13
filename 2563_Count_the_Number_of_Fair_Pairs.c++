class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int lwr = lower - nums[i];
            int upr = upper - nums[i];

            auto up= upper_bound(nums.begin() + i +1, nums.end(), upr);
            auto low = lower_bound(nums.begin()+ i +1, nums.end(), lwr);

            ans += up-low;
        }
        return ans;
    }
};