class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        int len=m*n;
        k=k%len;
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int old_ind =i*n+j;
                int new_ind=(old_ind+k)%len;

                int newrow=new_ind/n;
                int newcol=new_ind%n;

                ans[newrow][newcol]=grid[i][j];

            }
        
        
       }
        return ans;
    }
};