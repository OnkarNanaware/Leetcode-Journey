class Solution {
public: int f(int n,int m,string& text1,string& text2,vector<vector<int>>&dp)
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
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        string t=s;
        reverse(s.begin(),s.end());
        return f(n-1,n-1,s,t,dp);
    }
};