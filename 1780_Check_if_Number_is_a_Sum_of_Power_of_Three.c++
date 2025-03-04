class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int bhaji=0;
    
            while(pow(3, bhaji)<=n){
                bhaji++;
            }
    
            while(n>0){
                if(n>=pow(3, bhaji)) n-=pow(3, bhaji);
                if( n>=pow(3, bhaji)) return false;
                bhaji--;
            }
            return true;
        }
    };