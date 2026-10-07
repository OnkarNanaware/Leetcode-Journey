class Solution {
public:
    int maxlen = 1;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1), cnt(n, 1);
      

        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev] && dp[prev] + 1 > dp[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                    cnt[i] = cnt[prev];
                } else {
                    if (nums[i] > nums[prev] && dp[prev] + 1 == dp[i]) {
                        cnt[i] += cnt[prev];
                    }
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        int nos=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxlen) nos+=cnt[i];
        }
        return nos;
    }
};