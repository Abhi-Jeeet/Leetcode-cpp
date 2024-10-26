class Solution {
public:
    int possibleStringCount(string word) {
        int total = 1;
        for(int i = 0;i<word.length();i++){
            int count = 1;
            while(i+1<word.length()&& word[i] == word[i+1]){
                count++;
                i++;
            }
            total += count -1 ;
        }
        return total;
    }
};