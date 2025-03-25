class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<pair<int, int>> h, v;
        for (auto &x : rectangles)
        {
            h.push_back({x[0], x[2]});
            v.push_back({x[1], x[3]});
        }
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        int cnt = 1;
        int prev = h[0].second;
        for (int i = 1; i < h.size(); i++)
        {
            if (h[i].first >= prev)
            {
                cnt++;
            }
            prev = max(prev, h[i].second);
        }
        if (cnt >= 3)
            return 1;
        cnt = 1;
        prev = v[0].second;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].first >= prev)
            {
                cnt++;
            }

            prev = max(prev, v[i].second);
        }
        if (cnt >= 3)
            return 1;
        return 0;
    }
};