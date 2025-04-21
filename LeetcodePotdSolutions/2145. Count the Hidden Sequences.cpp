class Solution
{
public:
#define ll long long

    int numberOfArrays(vector<int> &d, int l, int u)
    {
        ll sum = 0;
        ll maxi = 0, mini = 0;
        int n = d.size();
        for (int i = 0; i < n; i++)
        {
            sum += d[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }

        ll Low = l - mini;
        ll High = u - maxi;
        return max(0LL, High - Low + 1);
    }
};