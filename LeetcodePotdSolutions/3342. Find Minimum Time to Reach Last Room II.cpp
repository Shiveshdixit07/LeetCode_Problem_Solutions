class Solution
{
public:
#define ll long long
    int minTimeToReach(vector<vector<int>> &arr)
    {

        int n = arr.size();
        int m = arr[0].size();
        long long res = INT_MAX;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        pq.push({0, 0, 0, 0});
        vector<vector<ll>> dis(n, vector<ll>(m, INT_MAX));
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ll d = it[0];
            ll u = it[1];
            ll v = it[2];
            ll move = it[3];
            if (dis[u][v] < d)
                continue;
            if (u == n - 1 && v == m - 1)
            {
                return d;
            }
            for (int i = 0; i < 4; i++)
            {
                int I = dir[i][0] + u;
                int J = dir[i][1] + v;
                if (I < 0 || J < 0 || I >= n || J >= m)
                    continue;
                ll toadd = ((move & 1) ? 2 : 1);
                if (dis[I][J] > max(arr[I][J] + toadd, d + toadd))
                {
                    dis[I][J] = max(arr[I][J] + toadd, d + toadd);
                    pq.push({dis[I][J], I, J, move + 1});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};