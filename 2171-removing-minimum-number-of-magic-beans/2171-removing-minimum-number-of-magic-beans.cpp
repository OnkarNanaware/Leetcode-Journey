class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
long long prev=0,total=0,res=LLONG_MAX;
for(auto it:beans){total+=it;}
for(int i=0;i<beans.size();i++){
int r=beans.size()-1-i;
long long rs=(long long)r*(long long)beans[i];
long long val=prev+((total-prev-beans[i])-rs);
res=min(res,val);
prev+=beans[i];
}
return res;
    }
};