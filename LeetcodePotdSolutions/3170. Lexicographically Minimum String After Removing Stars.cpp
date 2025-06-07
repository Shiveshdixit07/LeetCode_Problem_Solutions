struct cmp
{
    bool operator()(pair<char, int> &a, pair<char, int> &b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second < b.second;
        }
    }
};
class Solution
{
public:
    string clearStars(string &s)
    {
        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
            {
                pq.push({s[i], i});
            }
            else
            {
                auto top = pq.top();
                pq.pop();
                s[top.second] = '0';
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0' && s[i] != '*')
                ans += s[i];
        }
        return ans;
    }
};