class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int maxi=num;

        for(int i=0; i<str.size(); i++){
            for(int j=i+1; j<str.size(); j++){
                swap(str[i], str[j]);
                maxi=max(maxi, stoi(str));
                swap(str[i], str[j]);
            }
        }
        return maxi;
    }
};