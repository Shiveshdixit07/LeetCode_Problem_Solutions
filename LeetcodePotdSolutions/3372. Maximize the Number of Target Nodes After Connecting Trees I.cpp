class Solution
{
public:
    int dfs(unordered_map<int, vector<int>> &adj, int curr, int par, int k)
    {
        if (k < 0)
            return 0;
        if (k == 0)
            return 1;
        int res = 1;
        for (auto &nextNode : adj[curr])
        {
            if (nextNode != par)
            {
                res += dfs(adj, nextNode, curr, k - 1);
            }
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size() + 1;
        vector<int> res(n, 0);
        int m = edges2.size() + 1;
        int sum = 0;
        unordered_map<int, vector<int>> adj1, adj2;
        for (auto &e : edges1)
        {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2)
        {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < m; i++)
        {
            sum = max(sum, dfs(adj2, i, -1, k - 1));
        }
        for (int i = 0; i < n; i++)
        {
            res[i] += dfs(adj1, i, -1, k) + sum;
        }
        return res;
    }
};