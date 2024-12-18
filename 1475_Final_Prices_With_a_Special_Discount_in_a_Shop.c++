class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans = prices;
        int n = prices.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(prices[i]>= prices[j]){
                    ans[i] = prices[i]-prices[j];
                    break;
                }                    
            }
        }
        return ans;
    }
};


//using stack
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //using stack
        int n = prices.size();
        stack<int>st;
        vector<int>result = prices;

        for(int i=0; i<n; i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                result[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};