class Solution {
public:
    int lastStoneWeightII(vector<int>& A) {
    int sumA = 0;

    for (int a : A)
        sumA += a;

    vector<bool> dp(sumA + 1, false);
    dp[0] = true;

    for (int a : A) {
        for (int i = sumA; i >= a; --i) {
            dp[i] = dp[i] || dp[i - a];
        }
    }

    for (int i = sumA / 2; i >= 0; --i) {
        if (dp[i])
            return sumA - 2 * i;
    }

    return 0;
}
};