class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int>less;
            vector<int>greater;
            vector<int>equal;
    
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==pivot){
                    equal.push_back(nums[i]);
                }
                else if(nums[i]<pivot){
                    less.push_back(nums[i]);
                }
                else{
                    greater.push_back(nums[i]);
                }
            }
    
            less.insert(less.end(), equal.begin(), equal.end());
            less.insert(less.end(), greater.begin(), greater.end());
            return less;
    
        }
    };