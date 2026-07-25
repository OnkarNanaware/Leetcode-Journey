class Solution {
public:
    bool checkValidString(string s) {
        long min=0,max=0;
        for(char c:s)
        {
            if(c=='(')
            {
                min++;
                max++;
            }else if(c==')')
            {
                min--;
                max--;
            }
            else
            {
                min--;
                max++;
            }
            if(min<0) min=0;//[-1,*] we are not considering it 
            if(max<0) return false; //range we are allowed is[0,pos_no]
        }
        return (min==0);
    }
};
//time complexity will O(n)
//space will be constant