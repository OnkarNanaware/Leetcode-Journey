#include<numeric>
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>pre;

        partial_sum(nums.begin(),nums.end(),back_inserter(pre));
        return pre;

    }
};