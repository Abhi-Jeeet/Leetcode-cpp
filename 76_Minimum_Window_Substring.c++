class Solution {
public:
//T.C -> O(2N) + O(M);
//S.C ->O(256)
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int count=0;
        int sIndex=-1;
        int left=0;
        int right=0;
        unordered_map<char,int>mp;
        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }
        while(right<s.size()){
            if(mp[s[right]]>0){
                count++;
                
            }
            mp[s[right]]--;
            while(count==t.size()){
                if((right-left+1 )< minLen){
                    minLen = right-left+1;
                    sIndex=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0)count--;
                left++;
            }
            right++;
        }
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }


};