class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &f)
    {
        vector<string> ans;
        int n = f.size();

        sort(f.begin(), f.end());
        for (int i = 0; i < n; i++)
        {
            if (ans.empty())
                ans.push_back(f[i]);
            else
            {
                if (!f[i].starts_with((ans.back() + "/")))
                {
                    ans.push_back(f[i]);
                }
            }
        }
        return ans;
    }
};