class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>>results;
        int i=0;
        int n=arr.size();
        while(i<n && arr[i][1]<newInterval[0])
        {
            results.push_back(arr[i]);
            i=i+1;
        }
        while(i<n && arr[i][0]<=newInterval[1])
        {
            newInterval[0]=min(newInterval[0],arr[i][0]);
            newInterval[1]=max(newInterval[1],arr[i][1]);
            i=i+1;

        }
        results.push_back(newInterval);
        while(i<n)
        {
            results.push_back(arr[i]);
            i=i+1;
        }
        return results;
       
        
    }
};