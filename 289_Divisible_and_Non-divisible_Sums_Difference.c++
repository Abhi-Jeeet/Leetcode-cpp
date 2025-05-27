class Solution {
public:
    int differenceOfSums(int n, int m) {
        vector<int>divisible;
        vector<int>notDivisible;

        for(int i=0; i<=n; i++){
            if(i%m!=0){
                notDivisible.push_back(i);
            }
            else{
                divisible.push_back(i);
            }
        }

        int sumDivisible=0;
        int sumNotDivisible=0;

        for(int i=0; i<divisible.size(); i++){
            sumDivisible+=divisible[i];
        }
        for(int i=0; i<notDivisible.size(); i++){
            sumNotDivisible+=notDivisible[i];
        }

        int ans = sumNotDivisible - sumDivisible;
        return ans;
        
    }
};