class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> arr;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        { 
             for(int j=0;j<nums.size();j++)
             {
                    if(abs(i-j)<=k && nums[j]==key)
                    {
                        arr.insert(i);
                    }
             }
           
        }

        //sort(arr.begin(),arr.end());
       vector<int> v(arr.begin(), arr.end());
        return v;
    }
};