class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre;
        partial_sum(nums.begin(), nums.end(), back_inserter(pre));

        int n = pre.size();
        int total = pre[n - 1];

        for (int i = 0; i < n; i++) {
            int leftSum = (i == 0) ? 0 : pre[i - 1];
            int rightSum = total - pre[i];

            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};