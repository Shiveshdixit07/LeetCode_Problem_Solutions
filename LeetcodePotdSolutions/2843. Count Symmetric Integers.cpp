class Solution
{
public:
    bool chk(int n)
    {
        string s = to_string(n);
        if (s.length() & 1)
            return 0;
        int i = 0;
        int c = 0;
        int len = s.length();
        for (i; i < len / 2; i++)
        {
            c += (s[i] - '0');
        }
        for (i; i < len; i++)
        {
            c -= (s[i] - '0');
        }
        return c == 0;
    }
    int countSymmetricIntegers(int low, int high)
    {
        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            if (chk(i))
                ans++;
        }
        return ans;
    }
};