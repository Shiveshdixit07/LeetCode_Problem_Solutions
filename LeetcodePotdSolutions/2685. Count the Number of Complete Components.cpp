class Solution
{
public:
    vector<vector<int>> adj;
    pair<int, int> dfs(int src, vector<int> &vis)
    {
        vis[src] = 1;
        int c = adj[src].size();
        int count = 1;
        for (auto child : adj[src])
        {
            if (!vis[child])
            {
                auto t = dfs(child, vis);
                c += t.first;
                count += t.second;
            }
        }
        return {c, count};
    }
    int countCompleteComponents(int n, vector<vector<int>> &e)
    {
        adj.assign(n, vector<int>());
        for (auto x : e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                auto t = dfs(i, vis);
                int temp = t.second * (t.second - 1);
                if (temp == t.first)
                    ans++;
            }
        }
        return ans;
    }
};