class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3]={0};
        int ans=0;
        int n=s.length();
        int left,right;
        left=0;
        // right=n-1;
        for(int right=0;right<n;right++)
        {
            freq[s[right]-'a']++;

        while(freq[0]>0&&freq[1]>0&&freq[2]>0)
        {
            ans+=n-right;
            freq[s[left]-'a']--;
            left++;
        }
        }
    return ans;}
};