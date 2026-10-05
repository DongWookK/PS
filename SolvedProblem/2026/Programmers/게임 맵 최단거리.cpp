#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int m = maps.size();
    int n = maps[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> distance(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    vector<int> dy = { 0, 0, 1, -1 };
    vector<int> dx = { 1, -1, 0, 0 };

    q.push({ 0, 0 });
    visited[0][0] = true;
    distance[0][0] = 1;

    while (!q.empty())
    {
        auto here = q.front();
        q.pop();

        int y = here.first;
        int x = here.second;

        if (y == m - 1 && x == n - 1) {
            return distance[y][x];
        }

        for (int i = 0; i < 4; ++i)
        {
            int new_y = y + dy[i];
            int new_x = x + dx[i];

            if (new_y < 0 || new_y >= m || new_x < 0 || new_x >= n) continue;

            if (!visited[new_y][new_x] && maps[new_y][new_x] == 1)
            {
                visited[new_y][new_x] = true;
                distance[new_y][new_x] = distance[y][x] + 1;
                q.push({ new_y, new_x });
            }
        }
    }

    return -1;
}