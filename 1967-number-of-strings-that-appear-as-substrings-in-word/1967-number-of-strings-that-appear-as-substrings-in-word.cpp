class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        //going simple throw the constraints are 100
        int cnt=0;
        for(const string &pattern:patterns)
        {
            if(word.find(pattern)!=string::npos) //if present we will simple count the word 
            {
               cnt++;
            }
        }
     return cnt;
     }
   
};