class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char currChar: s){
            if(!st.empty() && ((currChar=='B' && st.top()=='A') || (currChar=='D' && st.top()=='C'))){
                st.pop();
            }
            else{
                st.push(currChar);
            }
        }
        return st.size();
    }
};