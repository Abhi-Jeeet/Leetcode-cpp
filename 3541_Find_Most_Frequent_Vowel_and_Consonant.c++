class Solution {
public:
    int maxFreqSum(string s) {
        int vowMax=0;
        int consoMax=0;
        map<char,int>vowels;
        map<char,int>conso;

        for(char it: s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u'){
                vowels[it]++;
            }
            else{
                conso[it]++;
            }
        }

        for(auto it: vowels){
            vowMax = max(vowMax, it.second);
        }

        for(auto it: conso){
            consoMax = max(consoMax, it.second);
        }
        return vowMax + consoMax;

    }
};