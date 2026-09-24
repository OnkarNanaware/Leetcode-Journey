class Solution {
public:long f(int ind,int buy,int cap,vector<int>&p,int n,vector<vector<vector<int>>>&dp)
 {  if(cap==0) return 0; // to track the maximum 2 transactions 
    if(ind==n) return 0;
    long profit=0;
    if(dp[ind][buy][cap]!=-1)
     return dp[ind][buy][cap];
        if(buy)
    { 
        profit=max((-p[ind])+f(ind+1,0,cap,p,n,dp),0+f(ind+1,1,cap,p,n,dp));

    }else
    { 
        profit=max(p[ind]+f(ind+1,1,cap-1,p,n,dp),0+f(ind+1,0,cap,p,n,dp));
    }
    return dp[ind][buy][cap]=profit;
 }
    int maxProfit(int k,vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,p,n,dp);
    }
};