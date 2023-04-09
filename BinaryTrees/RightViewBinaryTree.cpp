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

private:
    map<int, int> inversepreorder(TreeNode *root, int level, map<int, int> &m)
    {

        if (root == NULL)
        {
            return m;
        }

        if (m.find(level) == m.end())
        {
            m[level] = root->val;
        }

        inversepreorder(root->right, level + 1, m);
        inversepreorder(root->left, level + 1, m);

        return m;
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        map<int, int> m;
        inversepreorder(root, 0, m);
        vector<int> ans;
        for (auto p : m)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
}