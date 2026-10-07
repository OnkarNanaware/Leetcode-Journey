class Solution {
public:

    bool compare(string& longer, string& shorter)
    {
        if (longer.length() != shorter.length() + 1)
            return false;

        int i = 0;
        int j = 0;

        while (i < longer.length() && j < shorter.length())
        {
            if (longer[i] == shorter[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;   // skip the extra character
            }
        }

        return j == shorter.length();
    }

    static bool compa(string& s, string& s2)
    {
        return s.size() < s2.size();
    }

    int longestStrChain(vector<string>& nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        vector<int> dp(n, 1);

        sort(nums.begin(), nums.end(), compa);

        int maxLen = 1;

        for (int i = 1; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (compare(nums[i], nums[prev]))
                {
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};