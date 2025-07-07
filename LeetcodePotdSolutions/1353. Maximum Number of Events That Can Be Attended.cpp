class Solution {
public:
    struct cmp {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    int maxEvents(vector<vector<int>>& e) {
        sort(e.begin(), e.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int i = 0;
        int ans = 0;
        int d = e[i][0];
        int n = e.size();
        for (i; i < n || !pq.empty();) {
            if (pq.empty() && i < n)
                d = e[i][0];
            while (i < n && e[i][0] <= d) {
                pq.push({e[i][0], e[i][1]});
                i++;
            }
            auto x = pq.top();
            pq.pop();
            if (x.second < d)
                continue;
            ans++;
            d = max(d + 1, x.first + 1);
        }
        return ans;
    }
};