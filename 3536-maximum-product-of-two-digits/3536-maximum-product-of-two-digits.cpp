class Solution {
public:
    int maxProduct(int n) {
        int d1=0;
        int d2=0;
        vector<int> digit;
        while(n>0)
        {
           int  d=n%10;
           digit.push_back(d);
            n=n/10;
           
        }
        sort(digit.begin(),digit.end());
        reverse(digit.begin(),digit.end());

   return (digit[0]*digit[1]);  }
};