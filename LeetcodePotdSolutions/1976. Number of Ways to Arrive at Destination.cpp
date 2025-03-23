class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<vector<pair<int, int>>> adj;
    int sd(int src, int n)
    {
        priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>,
                       greater<pair<unsigned long long, int>>>
            pq;
        vector<pair<unsigned long long, int>> dis(n, {LLONG_MAX, 0});
        pq.push({0, src});
        dis[src] = {0, 1};

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            unsigned long long d = top.first;
            unsigned long long u = top.second;
            if (d > dis[u].first)
                continue;
            for (auto x : adj[u])
            {
                unsigned long long v = x.first;
                unsigned long long w = x.second;
                unsigned long long temp = w + d;
                if (temp < dis[v].first)
                {
                    dis[v] = {temp, dis[u].second};
                    pq.push({dis[v].first, v});
                }
                else if (temp == dis[v].first)
                {
                    dis[v].second += dis[u].second;
                    dis[v].second %= mod;
                }
            }
        }
        return dis[n - 1].second;
    }
    int countPaths(int n, vector<vector<int>> &r)
    {
        adj.assign(n, vector<pair<int, int>>());
        for (auto x : r)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        return sd(0, n);
    }
};