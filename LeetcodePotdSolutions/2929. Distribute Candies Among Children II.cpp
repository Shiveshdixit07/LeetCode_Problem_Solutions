class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        int t = min(n, limit);
        long long res = 0;
        for (int i = 0; i <= t; i++)
        {
            int temp = n - i;
            if (temp <= 2 * limit)
            {
                if (temp < limit)
                {
                    res += ((temp) + 1);
                }
                else
                {
                    res += (limit - (temp - limit) + 1);
                }
            }
        }
        return res;
    }
};