class Solution {
public:
 int f(int l,int r,vector<int>&nums,vector<vector<int>>&dp)
 { 
    if(l+1==r) return 0;
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }

    int maxi=0;
    for(int k=l+1;k<r;k++)
    {
        int coins=f(l,k,nums,dp)+f(k,r,nums,dp)+nums[l]*nums[k]*nums[r];
        maxi=max(maxi,coins);
    }
    return dp[l][r]=maxi;
 }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,nums.size()-1,nums,dp);
    }
};