class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        int fresh_oranges = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 2) {
                    q.push({ i, j });
                }
                else if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }

        if (fresh_oranges == 0) return 0;

        int dr[4] = { 0, 0, 1, -1 };
        int dc[4] = { 1, -1, 0, 0 };
        int minute = 0;

        while (!q.empty()) {
            int q_size = q.size();
            bool corrupted_any = false;

            for (int i = 0; i < q_size; ++i) {
                auto cd = q.front();
                q.pop();

                for (int j = 0; j < 4; ++j) {
                    int new_r = cd.first + dr[j];
                    int new_c = cd.second + dc[j];

                    if (new_r < 0 || new_r >= r || new_c < 0 || new_c >= c) continue;
                    if (grid[new_r][new_c] != 1) continue;

                    grid[new_r][new_c] = 2;
                    fresh_oranges--;
                    corrupted_any = true;

                    q.push({ new_r, new_c });
                }
            }

            if (corrupted_any) {
                ++minute;
            }
        }

        return (fresh_oranges == 0) ? minute : -1;
    }
};