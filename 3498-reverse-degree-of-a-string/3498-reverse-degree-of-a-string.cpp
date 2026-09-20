class Solution {
public:
    int reverseDegree(string s) {
        int count=1;
        int res=0;
        for(char ch:s)
        {
            int value='z'-ch+1;
            res+=value*count;
            count++;

        }
        return res;
    }
};