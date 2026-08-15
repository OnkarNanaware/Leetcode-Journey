#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Expand the window by adding the current element
            freq[nums[right]]++;

            // Shrink the window if the current element's frequency exceeds k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // Update maximum length for the current valid window
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};