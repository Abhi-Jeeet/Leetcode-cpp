class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        for(char ch: allowed){
            mp[ch]++;
        }
        int count=0;
        for(int i=0; i< words.size(); i++){
            string word=words[i];
            bool tChar=true;
            for(char ch: word){
                if(mp.find(ch)==mp.end()){
                    tChar=false;
                }
            }
            if(tChar){
                count++;
            }
        }
        return count;
    }
};