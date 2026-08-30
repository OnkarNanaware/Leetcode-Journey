class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        // Find minimum and maximum values
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        // Find their positions
        int minPos = -1;
        int maxPos = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == mini) {
                minPos = i;
            }

            if (nums[i] == maxi) {
                maxPos = i;
            }
        }

        // Option 1:
        // Delete both from the front
        int front = max(minPos, maxPos) + 1;

        // Option 2:
        // Delete both from the back
        int back = n - min(minPos, maxPos);

        // Option 3:
        // Delete one from front and one from back
        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};