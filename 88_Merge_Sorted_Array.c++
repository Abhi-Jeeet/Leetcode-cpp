class Solution {
public:
    void mergeArray(vector<int>& nums1, int m, vector<int>& nums2, int n, vector<int>& ans){
        for(int i=0; i<m; i++){
            ans.push_back(nums1[i]);
        }
        for(int j=0; j<n; j++){
            ans.push_back(nums2[j]);
        }

        sort(ans.begin(), ans.end());
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        mergeArray(nums1, m, nums2, n, ans);

        for(int i=0; i<ans.size(); i++){
            nums1[i]=ans[i];
        }

    }
};