class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int length = 0;
        int i = n - 1;

        // Skip trailing spaces
        while(i >= 0 && s[i] == ' ')
            i--;

        //  Count last word characters
        while(i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};