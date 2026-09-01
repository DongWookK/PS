class Solution {
public:
    int CalcStep(const vector<int>& cost, vector<int>& cache, int step)
    {
        if (step >= cost.size()) return 0;

        int& ret = cache[step];
        if (ret != -1) return ret;

        return ret = cost[step] + min(CalcStep(cost, cache, step + 1), CalcStep(cost, cache, step + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(), -1);

        return min(CalcStep(cost, cache, 0), CalcStep(cost, cache, 1));
    }
};