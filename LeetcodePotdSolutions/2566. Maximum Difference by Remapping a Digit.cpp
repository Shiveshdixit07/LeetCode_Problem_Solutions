class Solution
{
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        string t = s;
        int n = s.length();
        int mx = 0, mn = 0;
        int i = 0;
        char c1 = 'a', c2 = 'a';
        for (i = 0; i < n; i++)
        {
            if (s[i] != '9' && c1 == 'a')
            {
                c1 = s[i];
            }
            if (s[i] != '0' && c2 == 'a')
                c2 = s[i];
        }
        if (c1 != 'a' || c2 != 'a')
        {

            for (int i = 0; i < n; i++)
            {
                if (s[i] == c1)
                    s[i] = '9';
                if (t[i] == c2)
                    t[i] = '0';
            }
        }

        int n1 = 0;
        int n2 = 0;
        i = 0;
        int j = 0;
        for (i; i < n; i++)
            if (s[i] != '0')
                break;
        for (j; j < n; j++)
            if (t[j] != '0')
                break;
        for (i; i < n; i++)
        {
            int tt = n - i - 1;
            n1 = n1 + pow(10, tt) * (s[i] - '0');
        }
        for (j; j < n; j++)
        {
            int tt = n - j - 1;
            n2 = n2 + pow(10, tt) * (t[j] - '0');
        }

        return n1 - n2;
    }
};