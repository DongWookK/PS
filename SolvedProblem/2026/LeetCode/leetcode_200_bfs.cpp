class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit_grid(m, vector<bool>(n, false));

        std::vector<int> dr{ -1, 1, 0, 0 };
        std::vector<int> dc{ 0, 0, -1, 1 };
        int result{};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0' || visit_grid[i][j]) continue;

                result++;
                queue<pair<int, int>> q{};
                q.push({ i, j });
                visit_grid[i][j] = true;

                while (!q.empty())
                {
                    auto land = q.front();
                    q.pop();

                    int r = land.first;
                    int c = land.second;

                    for (int k = 0; k < 4; ++k)
                    {
                        int new_r = r + dr[k]; // 세로축 이동은 m과 비교
                        int new_c = c + dc[k]; // 가로축 이동은 n과 비교

                        // 경계 조건 체크 (정확하게 세로는 m, 가로는 n)
                        if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) continue;
                        if (visit_grid[new_r][new_c] || grid[new_r][new_c] == '0') continue;

                        visit_grid[new_r][new_c] = true;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }

        return result;
    }
};