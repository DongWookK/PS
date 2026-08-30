class Solution {
private:
    std::vector<int> memo;

    int solve(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (memo[n] != -1) return memo[n];

        return memo[n] = solve(n - 1) + solve(n - 2);
    }

public:
    int climbStairs(int n) {
        memo.assign(n + 1, -1);
        return solve(n);
    }
};