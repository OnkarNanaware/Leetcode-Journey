class Solution {
public:
    int distinctSubseqII(string s) {

        int n = s.length();

        vector<long long> dp(n + 1, 0);
        vector<int> last(256, -1);

        dp[0] = 1;

        const long long MOD = 1e9 + 7;

        for (int i = 1; i <= n; i++) {

            // Take + Skip
            dp[i] = 2 * dp[i - 1] % MOD;

            char ch = s[i - 1];

            // Remove duplicate subsequences
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + MOD) % MOD;
            }

            // Update last occurrence
            last[ch] = i - 1;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};