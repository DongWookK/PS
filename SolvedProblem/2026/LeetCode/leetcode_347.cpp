class Solution {
public:
    struct freq
    {
        int num{};
        int count{};
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m{};
        auto comp = [](freq& a, freq& b) { return a.count > b.count; };
        priority_queue<freq, vector<freq>, decltype(comp)> pq;

        for (int num : nums)
        {
            auto it = m.find(num);
            if (m.end() == it)
            {
                it = m.emplace(num, 0).first;
            }

            it->second++;
        }

        for (auto it : m)
        {
            pq.push({ it.first, it.second });

            while (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().num);
            pq.pop();
        }

        return result;
    }
};