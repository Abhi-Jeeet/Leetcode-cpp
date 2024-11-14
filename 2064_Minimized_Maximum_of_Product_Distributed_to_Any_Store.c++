class Solution {
public:
    bool isPossible(int n, vector<int>& quantities, int mid){
        int stores = 0;
        for(auto x: quantities){
            stores+=x/mid;
            if(x%mid){
                stores++;
            }
            if(stores>n){
                return 0;
            }
        }
        return stores<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1,end = 100000, ans=-1;
        while(start<=end){
            int mid = start+(end - start)/2;
            if(isPossible(n, quantities, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};