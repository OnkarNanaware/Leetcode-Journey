class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(int x:nums)
        {
            tsum+=x;
        }
        if(tsum %2!=0) return false;
        int tar=tsum/2;
       vector<bool>dp(tar+1,false);
       dp[0]=true;//base case bhul gya tha 
        for(int z:nums)
        {
            for(int j=tar;j>=z;j--)
            {
            dp[j]=dp[j]||dp[j-z];
            }
        }
         return dp[tar];
    }
   
};