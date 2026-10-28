class Solution {
public:

     int bincount(int n)
 { int cnt=0;
    while(n>0)
    {
        if(n%2==1)
        {
            cnt++;
        }
        n=n/2;
    }
    return cnt;
 }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){

            if(bincount(i)==k)
            {
              sum+=nums[i];
            }

        }
        return sum;
    }
};