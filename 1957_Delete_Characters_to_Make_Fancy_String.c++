class Solution {
public:
    string makeFancyString(string s) {
        char prev=s[0];
        int freq = 1;
        string ans = "";
        ans.push_back(s[0]);

        for(int i=1; i<s.length(); i++){
            if(s[i] == prev){
                freq++;
            }
            else{
                prev=s[i];
                freq=1;
            }

            if(freq < 3){
                ans.push_back(s[i]);
            }

        }
        return ans;
    }
};