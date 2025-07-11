class Solution
{
public:
    int rooms[100];
    int mostBooked(int n, vector<vector<int>> &m)
    {
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        set<long long> st;
        sort(m.begin(), m.end());
        for (int i = 0; i < m.size(); i++)
        {
            long long s = m[i][0];
            long long e = m[i][1];
            while (!pq.empty() && pq.top().first <= s)
            {
                auto [x, y] = pq.top();
                pq.pop();
                st.insert(y);
            }

            if (st.empty())
            {
                if (pq.size() < n)
                {
                    rooms[pq.size()]++;
                    pq.push({e, pq.size()});
                }
                else
                {
                    auto [x, y] = pq.top();
                    pq.pop();
                    rooms[y]++;
                    pq.push({x + e - s, y});
                }
            }
            else
            {
                auto x = *st.begin();
                st.erase(st.begin());
                rooms[x]++;
                pq.push({e, x});
            }
        }
        long long mx = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (rooms[i] > mx)
            {
                mx = rooms[i];
                ans = i;
            }
        }

        return ans;
    }
};