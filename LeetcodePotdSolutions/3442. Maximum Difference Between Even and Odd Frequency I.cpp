class Solution
{
public:
    int maxDifference(string &s)
    {
        int n = s.length();
        int mx = 0;
        int mn = 101;
        int ht[26] = {0};
        for (int i = 0; i < n; i++)
        {
            ht[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            int x = ht[i];
            if (x > 0 && (x & 1))
            {
                mx = max(mx, x);
            }
            else if (x > 0)
            {
                mn = min(mn, x);
            }
        }
        return mx - mn;
    }
};