class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count=0;
            int n = nums.size();
            for(int i=0; i<n; i++){
                string s = to_string(nums[i]);
                int len = s.length();
                if(len%2==0){
                    count++;
                }
            }
            return count;
        }
    };