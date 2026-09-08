class Solution {
public:
    int countCommas(int n) {
        int r=0;
        for(int a=1;a<=n;++a)
        {
            if(a>999)
            {
                r+=1;
            }
        } return r;
    }
};