class Solution
{
public:
    int val(string &a, int n)
    {
        int v = 0;
        for (int i = 0; i < n; i++)
        {
            v = v * 10 + (a[i] - '0');
        }
        return v;
    }
    int maxDiff(int num)
    {
        string a = to_string(num);
        string b = a;
        char c1 = 'a', c2 = 'a';
        int n = a.length();
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != '9' && c1 == 'a')
            {
                c1 = a[i];
            }
            if (b[i] != '1' && b[i] != '0' && c2 == 'a')
            {
                if (i == 0)
                    f = 0;
                c2 = b[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == c1)
                a[i] = '9';
            if (b[i] == c2 && !f)
                b[i] = '1';
            else if (b[i] == c2 && f)
            {
                b[i] = '0';
            }
        }
        return val(a, n) - val(b, n);
    }
};