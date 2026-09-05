class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       
        int n=nums.size();
        vector<int> Tsuffix(n);
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
          mn=min(mn,nums[i]);
          Tsuffix[i]=mn;
        }
        int mx=-1;
        for(int j=0;j<n;j++)
        {
            mx=max(mx,nums[j]);
            mn=Tsuffix[j];
            if(mx-mn<=k)
              return j;
        }
        return -1;
             
        
        
    }
};