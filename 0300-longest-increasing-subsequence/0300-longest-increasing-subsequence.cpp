class Solution {
public:
    int solve(int i, int prev_idx, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        
        if (dp[i][prev_idx + 1] != -1) return dp[i][prev_idx + 1];
        
        // Option 1: Do not include nums[i]
        int notTake = solve(i + 1, prev_idx, nums, dp);
        
        // Option 2: Include nums[i] (if strictly greater than previous element)
        int take = 0;
        if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }
        
        return dp[i][prev_idx + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp table sized [n][n + 1] to account for prev_idx = -1 offset
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }
};