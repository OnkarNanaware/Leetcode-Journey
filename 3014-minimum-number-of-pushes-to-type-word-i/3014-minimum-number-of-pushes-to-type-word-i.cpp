class Solution {
public:
    int minimumPushes(string word) {
        int len = word.length();
        int ans = 0;
        int multiplier = 1;

        while (len > 0) {
            int take = min(len, 8);
            ans += take * multiplier;
            len -= take;
            multiplier++;
        }

        return ans;
    }
};