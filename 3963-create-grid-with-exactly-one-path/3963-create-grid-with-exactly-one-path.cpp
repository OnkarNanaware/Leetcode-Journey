class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // Move right along the first row
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        // Move down along the last column
        for (int i = 1; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};