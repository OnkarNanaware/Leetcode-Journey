class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long cnt = 0;
         //for each no we count there freq 
        for (int i = 0; i < n; i++) {
            int freq = 0;
             //WE COUNT THE FREQ of the targert if it match with the our expected as given 
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    freq++;
                }

                int len = j - i + 1;
                 //more than half then it is the valid subarray 
                if (freq > len / 2) {
                    cnt++;
                }
            }
        }
       //simple thing is no need print simply count the occurances 
        return cnt;
    }
};