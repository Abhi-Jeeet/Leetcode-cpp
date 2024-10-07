class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        do{
            string res = "";
            for(int num: nums){
                res += bitset<8>(num).to_string().substr(bitset<8>(num).to_string().find('1'));
            }
            int dv = stoi(res,0,2);
            ans = max(ans, dv);

        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};