class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        if(nums1.size()%2==1){
            for(int num:nums2){
                res ^= num;
            }
        }
        if(nums2.size()%2==1){
            for(int num:nums1){
                res^=num;
            }
        }
        return res;
    }
};