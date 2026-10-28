
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<long long, int>> a(n);

        for (int i = 0; i < n; i++) {
            a[i].first = nums[i];
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        int l = 0, r = n - 1;

        while (l < r) {
            long long sum = a[l].first + a[r].first;

            if (sum == target) {
                return {a[l].second, a[r].second};
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return {};
    }
};
