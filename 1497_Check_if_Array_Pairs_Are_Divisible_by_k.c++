class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>freq(k,0);
        for(auto it: arr){
            int rem = ((it%k)+k)%k;
            freq[rem]++;
        }
        if(freq[0]%2!=0){
            return false;
        }

        for(int i=1; i<k; i++){
            if(freq[i]!=freq[k-i]){
                return false;
            }
        }
        return true;
    }
};