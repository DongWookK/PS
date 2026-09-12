class Solution {
public:
    vector<int> find_partial_match(string pattern)
    {
        int m = pattern.length();
        vector<int> pi(pattern.size(), 0);
        int j = 0;
        for (int i = 1; i < m; ++i)
        {
            while (j > 0 && pattern[i] != pattern[j]) // 마지막 일치했돈곳을 찾는다.
            {
                j = pi[j - 1];
            }

            if (pattern[i] == pattern[j])
            {
                j++;
                pi[i] = j;
            }
        }
        return pi;
    }

    int strStr(string haystack, string needle)
    {
        vector<int> pi = find_partial_match(needle); // 앞서 만든 테이블 활용
        vector<int> result;
        int n = haystack.length();
        int m = needle.length();
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                if (j == m - 1) { // 패턴 전체를 찾았을 때
                    return (i - m + 1);
                    j = pi[j];
                }
                else {
                    j++;
                }
            }
        }
        return -1;
    }
};