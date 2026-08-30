class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // 시작점이나 끝점이 벽(1)이면 도달 불가능
        if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1) {
            return -1;
        }

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        visited[0][0] = true;

        vector<int> dr{ 0, 1, -1, 0, 1, -1, -1, 1 };
        vector<int> dc{ 1, 0, 0, -1, -1, 1, -1, 1 };

        // 시작점도 경로에 포함되므로 path_length는 1부터 시작
        int path_length = 1;

        while (!q.empty()) {
            int current_level_size = q.size();

            for (int i = 0; i < current_level_size; ++i) {
                auto [curr_r, curr_c] = q.front();
                q.pop();

                // 목적지(오른쪽 아래)에 도달했다면 현재까지의 경로 길이 반환
                if (curr_r == r - 1 && curr_c == c - 1) {
                    return path_length;
                }

                for (int d = 0; d < 8; ++d) {
                    int nr = curr_r + dr[d];
                    int nc = curr_c + dc[d];

                    if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                        if (!visited[nr][nc] && grid[nr][nc] == 0) {
                            visited[nr][nc] = true;
                            q.push({ nr, nc });
                        }
                    }
                }
            }
            path_length++;
        }

        return -1;
    }
};