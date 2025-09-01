class Solution
{
public:
    double change(double x, double y) { return (x + 1) / (y + 1) - x / y; }
    double maxAverageRatio(vector<vector<int>> &c, int e)
    {
        double ans = 0;
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < c.size(); i++)
        {
            pq.push({change(c[i][0], c[i][1]), i});
        }
        for (int i = 0; i < e; i++)
        {
            auto top = pq.top();
            pq.pop();
            c[top.second][0] += 1;
            c[top.second][1] += 1;
            pq.push({change(c[top.second][0], c[top.second][1]), top.second});
        }
        for (int i = 0; i < c.size(); i++)
        {
            ans += c[i][0] / (1.0 * c[i][1]);
        }
        return ans / c.size();
    }
};