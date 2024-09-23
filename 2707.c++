class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n= s.size();

        vector<int> dp(n+1,n);

        dp[0]=0;

        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                string sub = s.substr(j, i-j);
                if(dict.find(sub) != dict.end()){
                    dp[i]=min(dp[i], dp[j]);
                }
            }
            dp[i]=min(dp[i], dp[i-1] +1);
        }

        return dp[n];
    }
};