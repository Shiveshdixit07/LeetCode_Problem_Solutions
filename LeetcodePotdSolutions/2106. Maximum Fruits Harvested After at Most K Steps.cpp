class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &f, int s, int k)
    {
        vector<int> v = {s, INT_MIN};
        int idx = lower_bound(f.begin(), f.end(), v) - f.begin();

        int l, r;
        int ans = 0;
        if (idx >= f.size())
        {
            l = idx - 1, r = idx;
        }
        else if (f[idx][0] == s)
        {
            ans += f[idx][1];
            l = idx - 1;
            r = idx + 1;
        }
        else
        {
            l = idx - 1, r = idx;
        }
        vector<pair<int, int>> left, right;
        int sum = 0;
        while (l >= 0)
        {
            sum += f[l][1];
            left.push_back({f[l][0], sum});
            l--;
        }
        if (!left.empty())
            reverse(left.begin(), left.end());
        sum = 0;
        while (r < f.size())
        {
            sum += f[r][1];
            right.push_back({f[r][0], sum});
            r++;
        }
        int rem = 0;
        int origk = k;
        for (int i = left.size() - 1; i >= 0; i--)
        {
            auto [la, lb] = left[i];
            k = origk - (s - la);
            if (k < 0)
                break;
            int idx = lower_bound(right.begin(), right.end(),
                                  make_pair(la + k, INT_MIN)) -
                      right.begin();
            if (idx >= right.size())
                idx--;
            if (idx >= 0 && right[idx].first - la > k)
                idx--;
            int rm = 0;
            auto [ra, rb] = (idx < 0) ? make_pair(la, 0) : right[idx];
            if (ra - la <= k)
                rm = rb;
            rem = max(rem, lb + rm);
            k = origk;
        }
        k = origk;
        for (int i = 0; i < right.size(); i++)
        {
            auto [ra, rb] = right[i];
            k = origk - (ra - s);
            if (k < 0)
                break;
            int idx = lower_bound(left.begin(), left.end(),
                                  make_pair(ra - k, INT_MIN)) -
                      left.begin();
            if (idx >= left.size())
                idx--;
            int lm = 0;
            if (idx >= 0 && ra - left[idx].first > k)
                idx--;
            auto [la, lb] = (idx < 0) ? make_pair(ra, 0) : left[idx];
            if (ra - la <= k)
                lm = lb;
            rem = max(rem, rb + lm);
            k = origk;
        }
        ans += rem;
        return ans;
    }
};