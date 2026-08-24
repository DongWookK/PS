class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.size(); ++i) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // 좌/우의 모든 결과값 조합 계산
                for (int l : left) {
                    for (int r : right) {
                        if (op == '+') result.push_back(l + r);
                        else if (op == '-') result.push_back(l - r);
                        else if (op == '*') result.push_back(l * r);
                    }
                }
            }
        }

        // 기저 조건: 연산자가 없어 쪼개지지 않은 경우 (순수 숫자)
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};

/*
오답

class Solution {
public:
    int compute(int n1, int n2, char op) {
        if (op == '+') return n1 + n2;
        if (op == '-') return n1 - n2;
        if (op == '*') return n1 * n2;
        return 0;
    }

    void exhaustive_search(vector<string> token, vector<int>& result) {
        // [수정 1] 기저 조건: 토큰이 숫자 1개만 남았을 때 결과에 추가하고 종료
        if (token.size() == 1) {
            result.push_back(stoi(token[0]));
            return;
        }

        for (int i = 1; i < token.size(); i += 2) {
            vector<string> compute_token = token;
            int res = compute(stoi(token[i-1]), stoi(token[i+1]), token[i][0]);

            compute_token[i-1] = to_string(res);
            compute_token.erase(compute_token.begin() + i, compute_token.begin() + i + 2);

            // [수정 2] 축소된 토큰으로 재귀 탐색
            exhaustive_search(compute_token, result);
        }
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<string> token;
        string temp = "";
        for (char ch : expression) {
            if (isdigit(ch)) {
                temp += ch;
            } else {
                if (!temp.empty()) {
                    token.push_back(temp);
                    temp.clear();
                }
                token.push_back(string(1, ch));
            }
        }
        if (!temp.empty()) token.push_back(temp);

        vector<int> results;
        exhaustive_search(token, results);

        return results;
    }
};
*/