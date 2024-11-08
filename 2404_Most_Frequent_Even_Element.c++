class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n =nums.size();
        map<int,int> mp;

        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
            
        }

        if(mp.empty()){
            return -1;
        }

        int maxFrequent = -1;
        int maxFrequency = 0;

        for(auto it: mp){
            if(it.second > maxFrequency){
                maxFrequency = it.second;
                maxFrequent = it.first;
            }
            else if(it.second == maxFrequency && it.first < maxFrequent){
                maxFrequent = it.first;
            }
        }
        return maxFrequent;
    }
};