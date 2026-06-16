class Solution {
public:
    // DFS 방식을 이용해 연결된 육지를 모두 방문하는 함수
    void visit(int x, int y, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visit_grid)
    {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (visit_grid[x][y] || grid[x][y] == '0') return;

        visit_grid[x][y] = true;
        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };

        // 상하좌우 재귀 호출
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            visit(nx, ny, m, n, grid, visit_grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        vector<vector<bool>> visit_grid(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1' && !visit_grid[i][j]) {
                    visit(i, j, m, n, grid, visit_grid);
                    ++result;
                }
            }
        }

        return result;
    }
};