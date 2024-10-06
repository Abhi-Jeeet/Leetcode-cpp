class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s2.length() > s1.length()){
            swap(s1,s2);
        }
        deque<string>d1,d2;

        stringstream ss1(s1);
        string word;
        while(ss1>>word){
            d1.push_back(word);
        }

        stringstream ss2(s2);
        while(ss2>>word){
            d2.push_back(word);
        }

        while(!d1.empty() && !d2.empty() && d1.front()==d2.front()){
            d1.pop_front();
            d2.pop_front();
        }

        while(!d1.empty() && !d2.empty() && d1.back()==d2.back()){
            d1.pop_back();
            d2.pop_back();
        }

        return d2.empty();
    }
};