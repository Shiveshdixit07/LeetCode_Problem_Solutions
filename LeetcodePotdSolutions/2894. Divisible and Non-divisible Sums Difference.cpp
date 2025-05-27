class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int total = n * (n + 1) / 2;
        int s1 = 0;
        for (int i = m; i <= n; i += m)
        {
            s1 += i;
        }
        int s2 = total - s1;
        return s2 - s1;
    }
};