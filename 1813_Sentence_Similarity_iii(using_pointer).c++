class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s2.length() > s1.length()){
            swap(s1,s2);
        }

        vector<string>v1,v2;

        stringstream ss1(s1);
        string word;
        while(ss1 >> word){
            v1.push_back(word);
        }

        stringstream ss2(s2);
        while(ss2 >> word){
            v2.push_back(word);
        }

        int i=0, j=v1.size()-1;
        int k=0, l=v2.size()-1;

        while(i < v1.size() && k < v2.size() && v1[i]==v2[k]){
            k++;
            i++;
        }

        while(l>=k && v2[l]==v1[j]){
            l--;
            j--;
        }

        if(l<k){
            return true;
        }
        return false;

    }
};