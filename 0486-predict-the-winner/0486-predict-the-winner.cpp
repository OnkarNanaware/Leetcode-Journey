class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Shortcut: If array length is even, Player 1 can always win 
        // by picking either all even or all odd indices.
        if (n % 2 == 0) return true;

        vector<int> dp(n);

        // Base case: single element ranges
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        // Build up range lengths from 2 to n
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[n - 1] >= 0;
    }
};