class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int nums:bills)
        {
            if(nums==5)
            {
              five=five+1;
            }
            else if(nums==10)
            { if(five)
               {  ten=ten+1;
                  five=five-1;
               }
               else
               {
                return false;
               }
            }
            else 
            {
                if(ten && five)
                {
                    ten=ten-1;
                    five=five-1;
                }
                else if(five>=3)
                {
                    five=five-3;
                }
                else
                {
                    return false;
                }
            }
        }
   return true; }
};