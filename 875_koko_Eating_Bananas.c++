//Binary Search Approach
// T.C -> O(n × log(max(piles)))
// S.C -> O(1);

class Solution {
public:
    long long func(vector<int>& piles, long long i, long long limit){
        long long totalHours = 0;
        for(int j=0; j<piles.size(); j++){
            totalHours+=(piles[j] + i-1)/i;
            if(totalHours > limit) return totalHours;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = maxElement;
        int ans = high;
        while(low<=high){
            long long mid = low + (high - low)/2;
            long long hours = func(piles,mid, h);
            if(hours<=h){
                ans = mid;
                high = mid-1;
               
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};