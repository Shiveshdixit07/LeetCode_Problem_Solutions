class Solution
{
public:
    string answerString(string &w, int n)
    {
        int len = w.length();
        char mx = w[0];
        int req = len - n + 1;
        if (req == len)
            return w;
        for (int i = 1; i < len; i++)
        {
            if (mx < w[i])
                mx = w[i];
        }
        string ans = "";
        for (int i = 0; i < len; i++)
        {
            if (w[i] == mx)
            {
                string temp = w.substr(i, min(len - i, req));
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};