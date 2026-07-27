class Solution {
public:
    bool canJump(vector<int>& nums) {
        //take i with the jump value add both check 
        //next index weather it is last then true else 
        // int i=0;
        // int n=nums.size();
        // while(i<n)
        // {
        //     int j=0;
        //     if(j+nums[j]>=n)//case 1 
        //     {
        //         return true;
        //     }else{
        //         j=j+nums[j];
        //     }
        //     i++;
        // }
        // return false;/

        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(i>mx) return false;

            mx=max(mx,i+nums[i]);
        }
        return true;
    }
};