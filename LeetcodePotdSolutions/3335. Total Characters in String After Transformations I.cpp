class Solution
{
public:
    const int mod = 1e9 + 7;

    int lengthAfterTransformations(string &s, int op)
    {
        vector<int> mp(26, 0);
        for (char c : s)
        {
            mp[c - 'a']++;
        }
        vector<int> aux(26, 0);

        while (op-- > 0)
        {
            aux.assign(26, 0);
            for (int j = 0; j < 25; j++)
            {
                aux[j + 1] = mp[j];
            }
            aux[0] = (aux[0] + mp[25]) % mod;
            aux[1] = (aux[1] + mp[25]) % mod;
            mp = move(aux);
        }

        int res = 0;
        for (auto &x : mp)
        {
            res = (res + x) % mod;
        }

        return res;
    }
};