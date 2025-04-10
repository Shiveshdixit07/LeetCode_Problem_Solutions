class Solution
{
public:
#define ll long long
    ll dp[17][2];
    ll solve(string &e, int idx, bool isTight, int suffLen, int limit)
    {
        if (idx + suffLen >= e.length())
            return 1;
        if (dp[idx][isTight] != -1)
            return dp[idx][isTight];
        ll v = 1;
        if (isTight)
        {

            int k = min((e[idx] - '0'), limit);
            if (k == e[idx] - '0')
            {
                v = k * solve(e, idx + 1, 0, suffLen, limit);
                v += solve(e, idx + 1, 1, suffLen, limit);
            }
            else
            {
                v = (k + 1) * solve(e, idx + 1, 0, suffLen, limit);
            }
        }
        else
        {
            int k = limit;
            v = (k + 1) * solve(e, idx + 1, 0, suffLen, limit);
        }
        return dp[idx][isTight] = v;
    }
    ll convert(string &s)
    {
        ll num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    bool check(string &e, int limit, int slen, ll num)
    {
        int i = 0;
        for (i; i + slen < e.length(); i++)
        {
            if (e[i] - '0' > limit)
                return 0;
        }
        ll v = 0;
        for (i; i < e.length(); i++)
        {
            v = v * 10 + e[i] - '0';
        }
        if (num <= v)
        {
            return 0;
        }
        return 1;
    }
    ll f(int limit, string &e, int n, ll num)
    {
        memset(dp, -1, sizeof(dp));
        ll v1 = solve(e, 0, 1, n, limit);
        if (check(e, limit, n, num))
            v1--;
        return v1;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string &s)
    {

        string e = to_string(finish);
        string Start = to_string(start - 1);
        ll num = convert(s);
        if (finish < num)
            return 0;
        int n = s.length();
        ll tillFinish = f(limit, e, n, num);
        ll tillStart = f(limit, Start, n, num);
        return tillFinish - tillStart;
    }
};