class Solution
{
public:
    int time = 0;
    vector<int> Xor;
    vector<vector<int>> adj;
    vector<int> in, out;
    void dfs(int src, int par, vector<int> &val)
    {
        in[src] = time++;
        Xor[src] = val[src];
        for (auto &v : adj[src])
        {
            if (v != par)
            {
                dfs(v, src, val);
                Xor[src] ^= Xor[v];
            }
        }
        out[src] = time++;
    }
    bool isAncestor(int u, int v) { return (in[u] < in[v] && out[u] > out[v]); }
    int minimumScore(vector<int> &nums, vector<vector<int>> &e)
    {
        int n = nums.size();
        Xor.resize(n);
        adj.resize(n);
        in.resize(n);
        out.resize(n);
        for (auto &ee : e)
        {
            adj[ee[0]].push_back(ee[1]);
            adj[ee[1]].push_back(ee[0]);
        }
        dfs(0, -1, nums);
        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isAncestor(i, j))
                {
                    int a = Xor[j];
                    int b = Xor[i] ^ a;
                    int c = Xor[0] ^ Xor[i];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
                else if (isAncestor(j, i))
                {
                    int a = Xor[i];
                    int b = Xor[j] ^ a;
                    int c = Xor[0] ^ Xor[j];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
                else
                {
                    int a = Xor[j];
                    int b = Xor[i];
                    int c = Xor[0] ^ Xor[i] ^ Xor[j];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return ans;
    }
};