class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(), skill.end());

        int target=skill[0] + skill[n-1];
        long long chemistry=0;

        int i=0;
        int j= n-1;
        while(i<j){
            if(skill[i] + skill[j]!=target){
                return -1;
            }
            else{
                chemistry+=skill[i]*skill[j];
                i++;
                j--;
            }
        }
        return chemistry;

    }
};