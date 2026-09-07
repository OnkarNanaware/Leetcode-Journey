class Solution {
public:
 int f(int ind,int t,vector<int>&nums,vector<vector<int>>&dp)
 {
    if(ind==0)
    {
        if(t%nums[0]==0) return t/nums[0];
        return 1e9;
    }
    if(dp[ind][t]!=-1)
    {
        return dp[ind][t];
    }
    int nottake=0+f(ind-1,t,nums,dp);
    int take=INT_MAX;               //amount -coins
    if(nums[ind]<=t) 
       {
         take=1+f(ind,t-nums[ind],nums,dp);
         }

    return dp[ind][t]=min(take,nottake);

 }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        //vector<int>nums(n);
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans= f(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};