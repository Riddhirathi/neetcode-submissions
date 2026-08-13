class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int area = 1;
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size()) {
            return 0;
        }
        if (grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
        area += dfs(grid, r - 1, c); // up
        area += dfs(grid, r + 1, c); // down
        area += dfs(grid, r, c - 1); // left
        area += dfs(grid, r, c + 1); // right
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    mx = max(mx, area);
                }
            }
        }

        return mx;
    }
};
