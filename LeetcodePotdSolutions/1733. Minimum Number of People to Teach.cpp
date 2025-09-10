class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &l,
                         vector<vector<int>> &f)
    {
        int result = l.size() + 1;
        unordered_set<int> st;

        for (auto &e : f)
        {
            int u1 = e[0] - 1;
            int u2 = e[1] - 1;
            bool flag = false;

            for (int x : l[u1])
            {
                for (int y : l[u2])
                {
                    if (x == y)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }

            if (!flag)
            {
                st.insert(u1);
                st.insert(u2);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;

            for (int x : st)
            {
                bool flag = false;
                for (int y : l[x])
                {
                    if (y == i)
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    cnt++;
            }

            result = min(result, cnt);
        }

        return result;
    }
};