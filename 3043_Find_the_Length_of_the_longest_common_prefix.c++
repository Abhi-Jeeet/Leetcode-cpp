class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;

        for(auto it:arr1){
            while(!st.count(it) && it>0){
                st.insert(it);
                it/=10;
            }
        }
        int maxLen=0;

        for(auto i:arr2){
            while(!st.count(i) && i>0){
                i/=10;
            }
            if(i>0){
                maxLen=max(maxLen, static_cast<int>(log10(i)+1));
            }
        }
        return maxLen;
    }
};