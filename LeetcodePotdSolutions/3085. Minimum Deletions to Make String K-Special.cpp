class Solution
{
public:
    int dp[26][26];
    int solve(int i, int j, int ht[], int k)
    {
        if (i == j)
            return 0;
        if (ht[i] - ht[j] <= k)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int o1 = solve(i + 1, j, ht, k) + (ht[i] - ht[j] - k);
        int o2 = solve(i, j - 1, ht, k) + ht[j];
        return dp[i][j] = min(o1, o2);
    }
    int minimumDeletions(string &word, int k)
    {
        int ht[26] = {0};
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            ht[word[i] - 'a']++;
        }
        sort(ht, ht + 26, greater<>());
        memset(dp, -1, sizeof(dp));
        int len = 0;
        for (len; len < 26; len++)
            if (ht[len] == 0)
                break;
        return solve(0, len - 1, ht, k);
    }
};