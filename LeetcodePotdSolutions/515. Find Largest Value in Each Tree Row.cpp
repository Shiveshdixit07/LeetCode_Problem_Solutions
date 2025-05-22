/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            int m = INT_MIN;
            for (int i = 0; i < sz; i++)
            {
                auto curr = q.front();
                q.pop();
                m = max(m, curr->val);

                if (curr->left)
                    q.push((curr->left));
                if (curr->right)
                    q.push((curr->right));
            }
            ans.push_back(m);
        }
        return ans;
    }
};