class Solution
{
public:
    vector<vector<int>> adj;

    void dfs(int src, vector<int> &vis, int dis, vector<int> &d)
    {
        int c = 0;
        vis[src] = 1;
        d[src] = max(dis, d[src]);
        for (auto child : adj[src])
        {
            if (!vis[child])
            {
                dfs(child, vis, dis + 1, d);
            }
        }
    }
    int closestMeetingNode(vector<int> &e, int n1, int n2)
    {
        adj.assign(e.size(), vector<int>());
        for (int i = 0; i < e.size(); i++)
        {
            if (e[i] != -1)
                adj[i].push_back(e[i]);
        }
        vector<int> d2(e.size(), -1);
        vector<int> vis(e.size());
        vector<int> d1(e.size(), -1);
        dfs(n1, vis, 0, d1);
        vis.assign(e.size(), 0);
        dfs(n2, vis, 0, d2);
        int ans = -1;
        int mini = INT_MAX;
        for (int i = 0; i < e.size(); i++)
        {
            if (d1[i] != -1 && d2[i] != -1 && mini > max(d1[i], d2[i]))
            {
                ans = i;
                mini = max(d1[i], d2[i]);
            }
        }
        return ans;
    }
};