class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        
        char toReplaceMax = ' ';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        string maxStr = s;
        if (toReplaceMax != ' ') {
            for (char& c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }

        
        string minStr = s;
        char toReplaceMin = s[0];
        char replaceWith = '1';
        if (toReplaceMin == '1') {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    replaceWith = '0';
                    break;
                }
            }
        }

        for (char& c : minStr) {
            if (c == toReplaceMin) c = replaceWith;
        }

        return stoi(maxStr) - stoi(minStr);
    }
};