class Solution {
public:
    string compressedString(string word) {
        string ans ="";
        int pos=0;

        while(pos<word.length()){
            int count = 0;
            char currChar=word[pos];
            
            while(pos< word.length() && count<9 && word[pos]==currChar){
                count++;
                pos++;
            }
            ans+=(count+'0') + currChar;
        }
        return ans;
        
    }
};