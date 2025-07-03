class Solution {
public:
    char kthCharacter(int k) {
        
        string ans = "a";
        while(ans.length()<k){
            string newAns = ans;
            for(auto it: ans){
                char nextChar = (it - 'a' + 1)%26 + 'a';
                newAns+=nextChar;
            }
            ans = newAns;
        }
        return ans[k-1];
    }
};