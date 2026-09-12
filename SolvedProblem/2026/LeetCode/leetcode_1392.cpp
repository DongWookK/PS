class Solution {
public:
    string longestPrefix(string s) {
        int m = s.size();
        vector<int> pi(m, 0);
        int j = 0;

        for (int i = 1; i < m; ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }

            if (s[j] == s[i]) {
                ++j;
                pi[i] = j;
            }
        }

        int len = pi.back();
        return s.substr(0, len);
    }
};