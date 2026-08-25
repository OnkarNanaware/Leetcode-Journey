class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        //now narr is sorted 
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int target=k;
        while(mp.count(target))
        {
            target+=k;
        }
        
        return target;
    }
};