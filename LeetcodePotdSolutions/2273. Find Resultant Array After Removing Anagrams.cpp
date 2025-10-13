class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        int n = words.size();
        vector<int> prev(26);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(26);
            bool same = 1;
            for (char c : words[i])
                curr[c - 'a']++;
            for (int j = 0; j < 26; j++)
                if (curr[j] != prev[j])
                {
                    same = 0;
                    break;
                }
            if (!same)
                ans.push_back(words[i]);
            prev = curr;
        }
        return ans;
    }
};