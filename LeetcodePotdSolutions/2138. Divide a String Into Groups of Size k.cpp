class Solution
{
public:
    vector<string> divideString(string &s, int k, char fill)
    {
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i < n; i += k)
        {
            string temp = "";
            for (int j = 0; j < k; j++)
            {
                temp += (i + j) < n ? s[i + j] : fill;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};