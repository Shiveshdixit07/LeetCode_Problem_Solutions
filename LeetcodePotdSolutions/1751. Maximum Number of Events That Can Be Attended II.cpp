class Solution {
public:
    vector<vector<int>> dp;
    int find(int s, int e, int val, vector<vector<int>>& ee) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ee[mid][0] > val) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
    int solve(vector<vector<int>>& e, int k, int idx) {
        if (idx == e.size() || k == 0)
            return 0;
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int ans = INT_MIN;
        int ntk = solve(e, k, idx + 1);
        int tk = solve(e, k - 1, find(idx + 1, e.size() - 1, e[idx][1], e)) +
                 e[idx][2];
        return dp[idx][k] = max(tk, ntk);
    }
    int maxValue(vector<vector<int>>& e, int k) {
        int n = e.size();
        dp.assign(n, vector<int>(k + 1, -1));
        sort(e.begin(), e.end());
        return solve(e, k, 0);
    }
};