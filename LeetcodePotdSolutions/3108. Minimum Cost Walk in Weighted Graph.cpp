class Solution
{
public:
    vector<vector<pair<int, int>>> adj;
    int dfs(int src, vector<int> &vis, int c)
    {
        vis[src] = c;
        int val = INT_MAX;
        for (auto child : adj[src])
        {
            val = (val & child.second);
            if (!vis[child.first])
            {
                val = (val & (dfs(child.first, vis, c)));
            }
        }
        return val;
    }
    vector<int> minimumCost(int n, vector<vector<int>> &e, vector<vector<int>> &q)
    {
        sort(e.begin(), e.end());
        int u = e[0][0];
        int v = e[0][1];
        int val = e[0][2];
        adj.assign(n, vector<pair<int, int>>());
        for (int i = 1; i < e.size(); i++)
        {
            int u1 = e[i][0];
            int v2 = e[i][1];
            int val2 = e[i][2];
            if (u == u1 && v == v2)
            {
                val = (val & val2);
            }
            else
            {
                adj[u].push_back({v, val});
                adj[v].push_back({u, val});
                u = u1;
                v = v2;
                val = val2;
            }
        }
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
        vector<int> vis(n);
        unordered_map<int, int> mp;
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int val = dfs(i, vis, c);
                mp[c] = val;
                c++;
            }
        }

        vector<int> ans(q.size(), -1);
        int i = 0;
        for (auto x : q)
        {
            int u = x[0];
            int v = x[1];
            if (vis[u] == vis[v])
            {
                ans[i] = mp[vis[u]];
            }
            i++;
        }
        return ans;
    }
};