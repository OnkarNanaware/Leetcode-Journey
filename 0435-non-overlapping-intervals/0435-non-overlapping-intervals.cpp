class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort by end time ascending
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        int lastentime = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastentime) {
                // Overlap found -> remove current interval (increment count)
                // DO NOT update lastentime!
                cnt++;
            } else {
                // No overlap -> keep current interval, update lastentime
                lastentime = intervals[i][1];
            }
        }

        return cnt;
    }
};