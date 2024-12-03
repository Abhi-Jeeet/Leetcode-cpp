class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        string ans;
        int i = 0;

        for(int j=0; j<n ;j++){
            if(i<spaces.size() && j==spaces[i] ){
                ans+=" ";
                i++;
                ans+=s[j];
            }
            else{
                ans+=s[j];
            }
        }
        return ans;
    }
};