class Solution {
public:
    bool uniformArray(vector<int>& arr) {
        // cheking the empty() condition
        //case 1
        sort(arr.begin(),arr.end());
        if(arr.empty()) return true; 

          if (arr[0] % 2 != 0) {
            return true;
        }

        //now chek for the first parity 
        bool check_starting=arr[0]%2==0;
        //checcking the remaining ones
        for(int i=0;i<arr.size();i++)
            {
                if(arr[i]%2!=0) 
                return false;
            }
        return true;
    }
};