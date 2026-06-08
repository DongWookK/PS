#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
int visited_order[100001];
int order = 1; // 방문 순서 카운터

void dfs(int r)
{
    //todo
    return;
}

int main() {
    // 1. 빠른 입출력을 위한 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    // 2. 정점 수 N, 간선 수 M, 시작 정점 R 입력
    if (!(cin >> n >> m >> r)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 4. 문제 조건: 인접 정점은 "오름차순"으로 방문
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(r);

    return 0;
}