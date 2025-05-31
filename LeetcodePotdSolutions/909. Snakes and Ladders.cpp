class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &b)
    {
        int ans = INT_MAX;
        int n = b.size();
        int total = n * n;
        vector<bool> vis(total + 1, 0);

        int temp[401] = {-1};

        int flag = 0;
        int s = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int j = 0, step = 1;
            if (flag)
            {
                j = n - 1;
                step = -1;
            }
            while (j >= 0 && j < n)
            {
                s++;
                temp[s] = b[i][j];
                j += step;
            }
            flag = flag ? 0 : 1;
        }

        queue<pair<int, int>> q;

        q.push({1, 0});
        vis[1] = 1;
        while (!q.empty())
        {
            int currIdx = (q.front()).first;
            int currAns = (q.front()).second;
            q.pop();

            if (temp[currIdx] != -1)
            {
                currIdx = temp[currIdx];
            }

            if (currIdx == total)
            {
                ans = min(ans, currAns);
            }

            int start = currIdx + 1;
            int end = min(currIdx + 6, total);

            currAns++;

            if (end == total)
            {
                ans = min(ans, currAns);
            }

            for (start; start <= end; start++)
            {
                if (!vis[start])
                {
                    q.push({start, currAns});
                    vis[start] = 1;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};