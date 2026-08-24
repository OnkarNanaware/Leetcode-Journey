class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int>pre;   
        partial_sum(nums.begin(),nums.end(),back_inserter(pre));
        int mini=*min_element(pre.begin(),pre.end());
        return max(1,1-mini);
    }

};