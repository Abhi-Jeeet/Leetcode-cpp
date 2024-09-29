class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>map;
        int count=0;
        for(int i=0; i<stones.length(); i++){
            char ch=stones[i];
            map[ch]++;
        }
        for(int i=0; i<jewels.length(); i++){
            char ch1=jewels[i];
            count+=map[ch1];
        }
        return count;
    }
};