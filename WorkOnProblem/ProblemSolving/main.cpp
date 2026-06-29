class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // 매분 오렌지는 4방향으로 썩은 오렌지가된다.
        // fresh orange가 하나도 없을때까지 갈때 가장 적게 걸리는 분.

        int r = grid.size();
        int c = grid[0].size();

        queue<std::pair<int, in>> q{};

        // vector<vector<int>> visit 
        array<int, r> dr{ 0,0,1,-1 };
        array<int, c> dc{ 1,-1,0,0 };

        for (int i = 0; i < r ++i)
        {
            for (int j = 0; j < c; ++j)
            {

            }
        }
    }
};