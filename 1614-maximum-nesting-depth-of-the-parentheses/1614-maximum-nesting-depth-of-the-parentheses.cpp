class Solution {
public:
    int maxDepth(string s) {
        //read the opening and closing 
        // inc the count 
        //till now the max opening willl be the answer
         long oc=0,cc=0;
         long  tc=0;
        for(char ch:s)
        {
            if(ch=='(')
            {
              oc++;
              tc=max(tc,oc);
            }else if(ch==')')
            {
                oc--;
            }
        }
     return tc;
        
    }
};