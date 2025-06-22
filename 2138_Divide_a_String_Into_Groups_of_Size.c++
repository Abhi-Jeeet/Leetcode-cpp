class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<int>res;
        int n = s.size();

        int curr=0;
        while(curr<n){
            string group = s.substr(curr,k);
            while(group.size()<k){
                group+=fill;
            }
            res.push_back(group);
            curr+=k;
        }
        return res;
    }
    
};