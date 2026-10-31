class Solution {
public:
    int m, n;
    int left = 0;
    int up = 1;
    int mod = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>>& grid, int camefrom)
    {
        if(i >= m || j >= n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        // Memoization check
        if(dp[i][j][camefrom] != -1)
            return dp[i][j][camefrom];

        // Mirror condition
        if(grid[i][j] == 1)
        {
            if(camefrom == left)
                return dp[i][j][camefrom] =
                       solve(i+1, j, grid, up);

            else
                return dp[i][j][camefrom] =
                       solve(i, j+1, grid, left);
        }

        // Normal cell
        int totalpathcount = 0;

        totalpathcount = (totalpathcount +
                         solve(i, j+1, grid, left)) % mod;

        totalpathcount = (totalpathcount +
                         solve(i+1, j, grid, up)) % mod;

        return dp[i][j][camefrom] = totalpathcount;
    }

    vector<vector<vector<int>>> dp;

    int uniquePaths(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(2, -1)
        ));

        return solve(0, 0, grid, left);
    }
};