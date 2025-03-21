class Solution
{
public:
    unordered_map<string, int> mp;
    unordered_set<string> present;
    vector<int> vis;
    bool dfs(string rc, vector<vector<string>> &ing)
    {
        int idx = mp[rc];
        vis[idx] = 1;
        for (auto req : ing[idx])
        {
            if (present.contains(req))
            {
                continue;
            }
            else if (mp.count(req) && vis[mp[req]] == 0)
            {
                if (!dfs(req, ing))
                {
                    return 0;
                }
                else
                {
                    present.contains(req);
                }
            }
            else
            {
                return 0;
            }
        }

        present.insert(rc);
        return 1;
    }
    vector<string> findAllRecipes(vector<string> &r,
                                  vector<vector<string>> &ing,
                                  vector<string> &sup)
    {

        int i = 0;
        vis.assign(r.size(), 0);
        for (auto &x : r)
        {
            mp[x] = i++;
        }
        for (auto &s : sup)
        {
            present.insert(s);
        }
        vector<string> ans;
        for (int i = 0; i < r.size(); i++)
        {
            if (present.contains(r[i]) || dfs(r[i], ing))
            {
                ans.push_back(r[i]);
            }
        }
        return ans;
    }
};
