class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> count;
        unordered_map<char, bool> visited;
        string result = ""; // This acts as our monotonic stack
        
        // 1. Count frequencies of all characters
        for (char ch : s) {
            count[ch]++;
        }
        
        // 2. Build the smallest subsequence
        for (char ch : s) {
            count[ch]--; // Decrement the remaining count of the current char
            
            // If the character is already in our result stack, skip it
            if (visited[ch]) continue;
            
            // Monotonic Stack logic: 
            // If the current char is smaller than the last char in our result,
            // AND that last char appears again later in the string, pop it!
            while (!result.empty() && ch < result.back() && count[result.back()] > 0) {
                visited[result.back()] = false; // Mark popped char as unvisited
                result.pop_back();
            }
            
            // Push current character to stack and mark as visited
            result.push_back(ch);
            visited[ch] = true;
        }
        
        return result;
    }
};
