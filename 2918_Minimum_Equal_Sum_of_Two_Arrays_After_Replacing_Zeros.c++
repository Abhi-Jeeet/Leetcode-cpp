class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long fSum=0, sSum=0;
        long long fZero=0, sZero=0;

        int n1 =nums1.size();
        int n2 = nums2.size();

        for(int i=0; i<n1; i++){
            fSum+=nums1[i];
            if(nums1[i]==0){
                fSum++;
                fZero++;
            }
        }

        for(int i=0; i<n2; i++){
            sSum+=nums2[i];
            if(nums2[i]==0){
                sSum++;
                sZero++;
            }
        }

        if(!fZero && fSum<sSum || !sZero && sSum<fSum){
            return -1;
        }
        else{
            return max(fSum, sSum);
        }

    }
};