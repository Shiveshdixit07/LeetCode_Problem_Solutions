class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        if (n == 1 && values[0] % k == 0)
            return 1;
        vector<vector<int>> vt(n);
        vector<int> degree(n);
        for (auto e : edges)
        {
            vt[e[0]].push_back(e[1]);
            vt[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        vector<long long> val;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            val.push_back(values[i]);
            if (degree[i] == 1)
                q.push(i);
        }
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            long long toadd = (val[top] % k == 0) ? 0 : val[top];
            if (toadd == 0)
                ans++;
            for (int nbr : vt[top])
            {
                if (degree[nbr] > 0)
                {
                    val[nbr] += toadd;
                    degree[nbr]--;
                    if (degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        return ans;
    }
};