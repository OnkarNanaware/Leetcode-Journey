class Solution {
public:

 int f(int i,vector<int>& arr, int k,vector<int>&dp)
 { int n=arr.size();
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];

    int maxi=INT_MIN;
    int ans=0;
    for(int j=i;j<min(n,i+k);j++)
    {
        maxi=max(maxi,arr[j]);

        int len=j-i+1;
        int sum=len*maxi+f(j+1,arr,k,dp);
        ans=max(ans,sum);
    }
    return dp[i]=ans;
 }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
       vector<int>dp(n+1,-1);
        return f(0,arr,k,dp);
    }
};