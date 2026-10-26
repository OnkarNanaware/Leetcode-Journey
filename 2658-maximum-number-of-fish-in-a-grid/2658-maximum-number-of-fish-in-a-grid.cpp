class Solution {
public:
    int  bfs(int sr, int sc, vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
       int sum=0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            sum+=grid[r][c];

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !vis[nr][nc] && grid[nr][nc]>=1) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] >=1) {
                  int  ans= bfs(i, j, grid, vis);
                    count=max(count,ans);
                }
            }
        }

        return count;
    }
};