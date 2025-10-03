class Solution
{
public:
    int trapRainWater(vector<vector<int>> &h)
    {
        int n = h.size();
        int m = h[0].size();
        int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
            pq.push({h[i][0], i, 0});
            pq.push({h[i][m - 1], i, m - 1});
        }
        for (int i = 0; i < m; i++)
        {
            vis[0][i] = 1;
            vis[n - 1][i] = 1;
            pq.push({h[0][i], 0, i});
            pq.push({h[n - 1][i], n - 1, i});
        }
        int ans = 0;
        while (!pq.empty())
        {
            auto [ht, x, y] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int X = x + dir[i][0];
                int Y = y + dir[i][1];
                if (X >= n || X < 0 || Y >= m || Y < 0 || vis[X][Y])
                    continue;
                if (h[X][Y] < ht)
                {
                    ans += ht - h[X][Y];
                }
                pq.push({max(h[X][Y], ht), X, Y});
                vis[X][Y] = 1;
            }
        }
        return ans;
    }
};