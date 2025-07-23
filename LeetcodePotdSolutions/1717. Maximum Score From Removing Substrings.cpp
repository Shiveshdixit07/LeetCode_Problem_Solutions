class Solution
{
public:
    pair<int, string> solve(string &s, int cost, char p, char q)
    {
        int n = s.length();
        stack<char> stk;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != q)
                stk.push(s[i]);
            else
            {
                if (!stk.empty() && stk.top() == p)
                {
                    cnt += cost;
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        int len = stk.size();
        string left(len, 'z');
        for (int i = len - 1; i >= 0; i--)
        {
            left[i] = stk.top();
            stk.pop();
        }
        return {cnt, left};
    }
    int maximumGain(string &s, int x, int y)
    {
        int n = s.length();
        int ans = 0;
        if (x > y)
        {
            auto [cnt, temp] = solve(s, x, 'a', 'b');
            ans += cnt;
            ans += solve(temp, y, 'b', 'a').first;
        }
        else
        {
            auto [cnt, temp] = solve(s, y, 'b', 'a');
            ans += cnt;
            ans += solve(temp, x, 'a', 'b').first;
        }
        return ans;
    }
};