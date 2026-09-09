class Solution {
public:int f(int n,int m,string& text1,string& text2,vector<vector<int>>&dp)
{
    if(n<0||m<0)
      return 0;
      if(dp[n][m]!=-1)
      {
        return dp[n][m];
      }
      if(text1[n]==text2[m])
       {
          return dp[n][m]=1+f(n-1,m-1,text1,text2,dp);
       }
       return dp[n][m]=0+max(f(n-1,m,text1,text2,dp),f(n,m-1,text1,text2,dp));
}
   int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        

        // Create DP table of size (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the table using bottom-up approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, extend LCS
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Get LCS length
        int lcs = dp[n][m];

        // Return total operations = deletions + insertions
        return (n - lcs) + (m - lcs);
    } 
        
    
};