#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int board[102][102] = { 0 };   // 0: 빈칸, 1: 테두리, 2: 내부

    for (auto& r : rectangle) {
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2; // 2배 좌표확장

        for (int x = x1; x <= x2; ++x)
        {
            for (int y = y1; y <= y2; ++y)
            {
                if (x1 < x
                    && x < x2
                    && y1 < y
                    && y < y2)
                {
                    board[x][y] = 2;
                }
                else if (board[x][y] != 2)
                {
                    board[x][y] = 1;
                }
            }
        }
    }

    int dist[102][102];
    for (auto& row : dist) for (int& d : row) d = -1;

    int sx = characterX * 2, sy = characterY * 2;
    int tx = itemX * 2, ty = itemY * 2;
    vector<int> dx{ 1, -1, 0, 0 };
    vector<int> dy{ 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ sx, sy });
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == tx && y == ty) return dist[x][y] / 2;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx > 101 || ny > 101) continue;
            if (board[nx][ny] != 1 || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
    return -1;
}