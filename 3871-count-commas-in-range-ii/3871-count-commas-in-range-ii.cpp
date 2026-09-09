class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
       // for(int a=1;a<=n;++a)
       // {
         for(long long p=1000;p<=n;p*=1000)
            {
                res+=n-p+1;
                if(p>n/1000) break;

           }//else
            // {
            //     res=0;
            // }
        // }
        return res;
     }
};