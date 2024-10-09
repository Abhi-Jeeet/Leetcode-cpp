class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            char curr=s[i];
            if(curr=='('){
                st.push(curr);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    count++;
                }
            }
        }
        if(st.empty()) return count;
        return st.size() + count;
        
        
    }
};