class Solution
{
public:
    vector<string> ans;
    int dp[1001][1001];
    bool chk(string &s, string &t)
    {
        if (s.length() != t.length())
            return 0;
        bool c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                if (c)
                    return 0;
                else
                    c = 1;
            }
        }
        return 1;
    }
    int solve(int i, int prev, vector<string> &w, vector<int> &g, int n)
    {
        if (i == n)
            return dp[i][prev + 1] = 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0, nottake = 0;
        if (prev == -1 || (g[i] != g[prev] && chk(w[i], w[prev])))
        {
            take = solve(i + 1, i, w, g, n) + 1;
        }
        nottake = solve(i + 1, prev, w, g, n);
        return dp[i][prev + 1] = max(take, nottake);
    }
    void construct(int i, int prev, vector<int> &g, int n, vector<string> &w)
    {
        if (i == n)
            return;
        int take = 0, nottake = 0;
        if (prev == -1 || (g[i] != g[prev] && chk(w[i], w[prev])))
        {
            if (i + 1 == n)
                take = 1;
            else
                take = dp[i + 1][i + 1] + 1;
        }
        if (i + 1 == n)
            nottake = 0;
        else
            nottake = dp[i + 1][prev + 1];
        if (take > nottake)
        {
            ans.push_back(w[i]);
            construct(i + 1, i, g, n, w);
        }
        else
        {
            construct(i + 1, prev, g, n, w);
        }
    }

    vector<string> getWordsInLongestSubsequence(vector<string> &w,
                                                vector<int> &g)
    {
        memset(dp, -1, sizeof(dp));
        int n = w.size();
        solve(0, -1, w, g, n);
        construct(0, -1, g, n, w);
        return ans;
    }
};