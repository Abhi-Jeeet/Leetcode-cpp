//Better Solution

class Solution {
public:
//T.C -> O(N) + O(N) = O(2N);
//S>C -> O(3), 3-> number of elements will present in the map
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left=0;
        int right=0;
        int maxLen =0;
        unordered_map<int,int>mp;

        while(right<n){
            mp[fruits[right]]++;

            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0){
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            if(mp.size()<=2){
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};