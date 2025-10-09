#define ll long long
class Solution
{
public:
    long long minTime(vector<int> &s, vector<int> &m)
    {
        int l1 = s.size();
        int l2 = m.size();
        vector<ll> temp(l1);
        for (int i = 0; i < l2; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                ll prev = (j == 0) ? 0 : temp[j - 1];
                temp[j] = 1LL * max(temp[j], prev) + s[j] * m[i];
            }
            if (i == l2 - 1)
                break;
            for (int j = l1 - 2; j >= 0; j--)
            {
                temp[j] = temp[j + 1] - s[j + 1] * m[i];
            }
        }
        return temp.back();
    }
};