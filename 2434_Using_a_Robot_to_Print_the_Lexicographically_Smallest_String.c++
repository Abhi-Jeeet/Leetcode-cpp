class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int>mp;
        for(auto it:s){
            mp[it]++;
        }
        string ans="";
        char minChar='a';
        stack<int>st;
        for(auto it:s){
            mp[it]--;
            st.push(it);
            while(minChar!='z'&&mp[minChar]==0)minChar++;
            while(!st.empty() && st.top()<=minChar){
                ans+=st.top();
                st.pop();
            }


        }
        return ans;

    }
};