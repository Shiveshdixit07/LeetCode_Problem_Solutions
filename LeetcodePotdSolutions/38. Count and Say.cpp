class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            vector<pair<char, int>> vt;
            char prev = ans[0];
            int cnt = 1;
            for (int j = 1; j < ans.length(); j++)
            {
                if (ans[j] == prev)
                {
                    cnt++;
                }
                else
                {
                    vt.push_back({prev, cnt});
                    cnt = 1;
                    prev = ans[j];
                }
            }
            vt.push_back({prev, cnt});
            string temp = "";
            for (int j = 0; j < vt.size(); j++)
            {

                temp += ('0' + vt[j].second);
                temp += vt[j].first;
            }
            ans = temp;
        }
        return ans;
    }
};