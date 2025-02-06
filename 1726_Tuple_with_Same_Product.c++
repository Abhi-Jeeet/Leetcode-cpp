class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const int n=nums.size();
        unordered_map<int, int> freq;// hash map less efficient
        freq.reserve(n*(n-1)/2);// reserve space
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                freq[nums[i]*nums[j]]++;
        // no need for sort
        int ans=0;
        for(auto& [x, f]: freq){ // easy single loop
            if (f>1) ans+=f*(f-1)*4;
        }
        return ans;
    }
};