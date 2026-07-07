class Solution {
public:
    int prim(const vector<vector<pair<int, int>>>& graph)
    {
        auto num_point = graph.size();
        int start = 0;
        int result = 0;
        int connected_nodes = 0;
        std::vector<bool> visited(num_point, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};

        pq.push({ 0, start });

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node]) continue;

            visited[node] = true;
            result += dis;
            ++connected_nodes;

            if (connected_nodes == num_point) break;

            for (const auto& [next_node, next_distance] : graph[node])
            {
                if (!visited[next_node])
                {
                    pq.push({ next_distance, next_node });
                }
            }
        }

        return result;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int num_point = points.size();
        vector<vector<pair<int, int>>> graph(num_point);

        for (int i = 0; i < num_point; ++i)
        {
            for (int j = i + 1; j < num_point; ++j)
            {
                auto distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({ j, distance });
                graph[j].push_back({ i, distance });
            }
        }

        return prim(graph);
    }
};