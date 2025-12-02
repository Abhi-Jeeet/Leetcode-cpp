//Brute Force
class Solution {
public:
    //T.C -> O(N^2);
    //S.C -> O(1);
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==-1)continue;
            for(int j=i+1; j<n; j++){
                if(nums[j]==-1) continue;
                if(nums[i] + nums[j] == k){
                    count++;
                    nums[i]=-1;
                    nums[j]=-1;
                    break;
                }
            }
        }
        return count;
    }
};

//Optimized
class Solution {
public:
    //T.C -> O(NlogN) + O(N)
    //S.C -> O(1);
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left=0;
        int right=n-1;
        int count=0;
        while(left<right){
            if(nums[left] + nums[right]==k){
                count++;
                left++;
                right--;
            }
            else if(nums[left] + nums[right] > k){
                right--;
            }
            else{
                left++;
            }
        }
        return count;
    }
};