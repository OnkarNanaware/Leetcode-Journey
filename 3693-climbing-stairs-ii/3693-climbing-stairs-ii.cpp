class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        // Step 1: Create DP array
        vector<int> dp(n + 1, INT_MAX);

        // Step 2: Base case
        dp[0] = 0;

        // Step 3: Build DP using loop
        for (int i = 1; i <= n; i++) {

            // Jump 1 step
            if (i >= 1) {
                dp[i] = min(dp[i],
                    dp[i - 1] + costs[i - 1] + 1);
            }

            // Jump 2 steps
            if (i >= 2) {
                dp[i] = min(dp[i],
                    dp[i - 2] + costs[i - 1] + 4);
            }

            // Jump 3 steps
            if (i >= 3) {
                dp[i] = min(dp[i],
                    dp[i - 3] + costs[i - 1] + 9);
            }
        }

        // Step 4: Return answer
        return dp[n];
    }
};