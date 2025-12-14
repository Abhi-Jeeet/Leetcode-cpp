//Brute Force

class Solution {
public:
    //T.C -> O(N);
    //S.C -> O(1);
    bool isPerfectSquare(int num) {
        for(long long i=1; i<=num; i++){
            long long square=i*i;
            if(square==num){
                return true;
            }
        }
        return false;
    }
};

//Binary Search

class Solution {
public:
    //T.C -> O(logN);
    //S.C -> O(1);
    bool isPerfectSquare(int num) {
        int low =1;
        int high = num;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long square = mid*mid;
            if(square==num){
                return true;
            }
            else if(mid*mid<num){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
        
    }
};