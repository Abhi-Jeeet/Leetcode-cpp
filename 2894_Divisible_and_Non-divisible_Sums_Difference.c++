class Solution {
public:
    int differenceOfSums(int n, int m) {
        vector<int> divisible;
        vector<int> notDivisible;

        for (int i = 1; i <= n; i++) {
            if ((i % m) != 0) // not divisible
                notDivisible.push_back(i);
            else { // divisible
                divisible.push_back(i);
            }
        }

        int divSum = 0;
        int notDivSum = 0;

        for (int i = 0; i < divisible.size(); i++) {
            divSum += i;
        }

        for (int i = 0; i < notDivisible.size(); i++) {
            notDivSum += i;
        }

        int ans = notDivSum - divSum;
        return ans;
    }
};