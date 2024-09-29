class Solution {
public:
    char kthCharacter(int k) {
        int count = 0;
        string ans = "a";
        while (count < k) {
            string new_ans = ans; // Create a copy of the current string to append new characters
            for (auto it : ans) {
                char next_char = (it - 'a' + 1) % 26 + 'a'; // Calculate the next character in the sequence
                new_ans += next_char;
            }
            ans = new_ans; // Update the string
            count = ans.length();
        }
        return ans[k - 1]; // Return the kth character (0-based index, hence k-1)
    }
};