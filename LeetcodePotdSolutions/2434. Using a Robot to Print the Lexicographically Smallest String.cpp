class Solution
{
public:
    string robotWithString(string &s)
    {
        int n = s.length();
        vector<char> vt(n);
        vt[n - 1] = 'z';
        char mn = s.back();
        for (int i = n - 2; i >= 0; i--)
        {
            vt[i] = mn;
            mn = min(mn, s[i]);
        }
        string ans = "";
        string left = "";
        for (int i = 0; i < n; i++)
        {
            left += s[i];
            if (vt[i] < s[i])
            {
                continue;
            }
            while (!left.empty() && left.back() <= vt[i])
            {
                ans += left.back();
                left.pop_back();
            }
        }
        while (!left.empty())
        {
            ans += left.back();
            left.pop_back();
        }
        return ans;
    }
};