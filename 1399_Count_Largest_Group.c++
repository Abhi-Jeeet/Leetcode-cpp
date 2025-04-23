class Solution {
    public:
        int countLargestGroup(int n) {
            int maxi = 0;
            int count = 0;
            unordered_map<int, int> mp;
            for (int i = 1; i <= n; i++) {
    
                int sum = 0;
                int temp=i;
                while(temp>0){
                    sum+=temp%10;
                    temp/=10;
                }
                
                mp[sum]++;
                maxi = max(maxi,mp[sum]);
    
            }
            
            for(auto& it:mp){
                if(it.second==maxi){
                    count++;
                }
            }
            return count;
        }
    };