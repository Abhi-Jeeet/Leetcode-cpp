class Solution {
public:
    int minimumLength(string s) {
        
        unordered_map<char, int> charFrequencyMap;
        for (char currentChar : s) {
            charFrequencyMap[currentChar]++;
        }

        
        int deleteCount = 0;
        for (auto& pair : charFrequencyMap) {
            int frequency = pair.second;
            if (frequency % 2 == 1) {
                
                deleteCount += frequency - 1;
            } else {
                
                deleteCount += frequency - 2;
            }
        }

        
        return s.length() - deleteCount;
    }
};