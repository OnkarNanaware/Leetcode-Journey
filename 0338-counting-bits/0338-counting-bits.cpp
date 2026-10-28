#include <bit> 
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
    vector<int> countBits(int n) {

        vector<int>arr;
        for(unsigned int i=0;i<=n;i++)
        {
            arr.push_back(bincount(i));
        }
        return arr;
        
    }
};