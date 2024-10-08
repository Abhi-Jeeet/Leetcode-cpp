class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count=0;
        for(int i=0; i<s.length(); i++){
            char curr=s[i];

            if(curr=='['){
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
        return (count+1)/2;
    }
};