class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            if (boxes[currentBox] == '1') {
                for (int newPosition = 0; newPosition < boxes.length();
                     newPosition++) {
                    answer[newPosition] += abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
};