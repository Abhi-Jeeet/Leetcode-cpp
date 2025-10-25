class Solution {
public:
    int totalMoney(int n) {
        int sum =0;
        int i=1;
        int j =0;

        for(int count=1; count<=n; count++){
            sum+=i;
            i++;
            if(i>7+j){
                j++;
                i=1+j;
            }
        }
        return sum;
    }
};