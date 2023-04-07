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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findH(root,ans);
        return ans;
    }

private:
    int findH(TreeNode* root,int& ans){
        if(root==NULL){
            return 0;
        }
        int lH=max(0,findH(root->left,ans));
        int rH=max(0,findH(root->right,ans));
        ans=max(ans,root->val+lH+rH);

        return max(lH,rH)+root->val;
    }
};