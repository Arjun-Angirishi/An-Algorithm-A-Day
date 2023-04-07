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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findHeight(root,diameter);
        return diameter;
    }

private:
    int findHeight(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }
        int lH=findHeight(root->left,diameter);
        int rH=findHeight(root->right,diameter);
        diameter=max(diameter,lH+rH);
        return 1+max(lH,rH);
    }
};