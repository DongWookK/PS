#include <string>
#include <vector>

using namespace std;

*/
int result_{};
int target_{};
void dfs(const vector<int>& numbers, int idx, int sum)
{
    if (idx == numbers.size())
    {
        if (sum == target_) result_++;
        return;
    }

    dfs(numbers, (idx + 1), sum + numbers[idx]);
    dfs(numbers, (idx + 1), sum - numbers[idx]);
}

int solution(vector<int> numbers, int target)
{
    target_ = target;
    dfs(numbers, 0, 0);
    return result_;
}