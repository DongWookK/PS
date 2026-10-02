#include <string>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& computers, vector<bool>& visited, int i)
{
    visited[i] = true;

    for (int j = 0; j < computers[i].size(); ++j)
    {
        if (computers[i][j] == 1
            && visited[j] == false)
        {
            dfs(computers, visited, j);
        }
    }

    return;
}

int solution(int n, vector<vector<int>> computers)
{
    vector<bool> visited(n, false);
    int answer{};

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
        {
            ++answer;
            dfs(computers, visited, i);
        }
    }

    return answer;
}