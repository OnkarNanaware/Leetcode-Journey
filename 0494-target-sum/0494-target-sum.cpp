class Solution {
public:
    int f(int ind,int target,vector<int>&nums)
    { 
        int ways=0;
        if(ind==0){
    if(target==nums[0])
    { ways++;}
    if(target==-nums[0])
    {
       ways++;
    }
    return ways;
        }
    int x=nums[ind];
    int take=f(ind-1,target-x,nums);
    int nottake=f(ind-1,target+x,nums);
    return take+nottake;
    
    
   }


    int findTargetSumWays(vector<int>& nums, int target) {
        int ind=nums.size();
        return f(ind-1,target,nums);
        
    }
};
