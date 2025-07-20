struct Trie
{
    unordered_map<string, Trie *> links;
    string str = "";
    bool mark = 0;
    Trie(string str = "") : str(str) {}

    void insert(vector<string> &path)
    {
        Trie *curr_node = this;
        for (string &s : path)
        {
            if (!curr_node->links.count(s))
                curr_node->links[s] = new Trie(s);
            curr_node = curr_node->links[s];
        }
    }
};

class Solution
{
public:
    Trie trie;
    unordered_map<string, Trie *> mp;
    vector<vector<string>> ans;

    string serial(Trie *curr_node)
    {
        if (curr_node->links.empty())
            return "";

        vector<pair<string, Trie *>> sorted(curr_node->links.begin(),
                                            curr_node->links.end());
        sort(sorted.begin(), sorted.end());

        string dir;
        for (auto &[str, child] : sorted)
            dir += "(" + str + serial(child) + ")";

        if (mp.count(dir))
        {
            mp[dir]->mark = 1;
            curr_node->mark = 1;
        }
        else
            mp[dir] = curr_node;

        return dir;
    }

    void to_Result(Trie *curr_node, vector<string> &path)
    {
        for (auto &[str, child] : curr_node->links)
        {
            if (child->mark)
                continue;
            path.push_back(str);
            ans.push_back(path);
            to_Result(child, path);
            path.pop_back();
        }
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        for (auto &path : paths)
            trie.insert(path);

        serial(&trie);
        vector<string> path;
        to_Result(&trie, path);
        return ans;
    }
};
