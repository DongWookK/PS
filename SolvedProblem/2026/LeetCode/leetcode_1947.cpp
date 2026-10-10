#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        // 인접 리스트
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& road : roads) {
            adj[road[0]].push_back({ road[1], road[2] });
            adj[road[1]].push_back({ road[0], road[2] });
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // 시작점 설정
        dist[0] = 0;
        ways[0] = 1;
        pq.push({ 0, 0 });

        while (!pq.empty()) {
            auto [cost, here] = pq.top();
            pq.pop();

            if (dist[here] < cost) continue;

            for (const auto& edge : adj[here]) {
                int there = edge.first;
                long long nextDist = cost + edge.second;

                if (dist[there] > nextDist) {
                    dist[there] = nextDist;
                    ways[there] = ways[here]; // 경우의 수를 물려받음
                    pq.push({ nextDist, there });
                }
                else if (dist[there] == nextDist) {
                    ways[there] = (ways[there] + ways[here]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};