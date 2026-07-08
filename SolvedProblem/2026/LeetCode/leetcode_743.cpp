class Solution {
public:
    int dijkstra(const int start, const int node_count, const vector<vector<pair<int, int>>>& graph)
    {
        const int INF = 1e9;
        vector<int> dist(node_count, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({ 0,start });

        while (!pq.empty())
        {
            auto current_time = pq.top().first;
            auto current_node = pq.top().second;
            pq.pop();

            if (dist[current_node] < current_time) continue;

            for (const auto& [time, next_node] : graph[current_node])
            {
                int next_time = current_time + time;

                if (next_time < dist[next_node]) {
                    dist[next_node] = next_time;
                    pq.push({ next_time, next_node });
                }
            }

        }

        int max_time = 0;
        for (int i = 1; i < node_count; ++i)
        {
            // 도달할 수 없는 노드가 있다면 -1 반환
            if (dist[i] == INF) return -1;

            // 3. 합산이 아니라 가장 오래 걸린 시간을 찾습니다.
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times)
        {
            graph[time[0]].push_back({ time[2],time[1] });
        }

        return dijkstra(k, n + 1, graph);
    }
};