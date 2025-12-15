//Brute Force
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int count=0;
        for(int i=0; i<n; i++){
                count++;
            for(int j = i+1; j<n; j++){
                if(prices[j]==prices[j-1]-1){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};




// Optimised solution
class Solution {
public:
    //T.C -> O(N);
    //S.C -> O(1);
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans=1;
        int count=1;
        for(int i=1; i<n; i++){
            if(prices[i] == prices[i-1]-1){
                count++;
            }
            else{
                count=1;
            }
            ans+=count;
        }
        return ans;
    }
};