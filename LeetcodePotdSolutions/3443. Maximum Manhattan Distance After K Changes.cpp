auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution
{
public:
    int maxDistance(string &S, int k)
    {
        int N = S.length();
        int ans = 0;
        int n = 0, s = 0, e = 0, w = 0;
        for (int i = 0; i < N; i++)
        {

            switch (S[i])
            {
            case 'N':
            {
                n++;
                break;
            }
            case 'S':
            {
                s++;
                break;
            }
            case 'E':
            {
                e++;
                break;
            }
            case 'W':
            {
                w++;
                break;
            }
            }
            int req = min(min(n, s) + min(e, w), k);
            ans = max(ans,
                      max(n, s) + max(e, w) - min(n, s) - min(e, w) + 2 * req);
        }
        return ans;
    }
};