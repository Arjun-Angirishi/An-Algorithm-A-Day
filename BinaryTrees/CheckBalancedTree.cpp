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

   int findH(TreeNode* root){
       if(root==NULL){
           return 0;
       }
       int lH=findH(root->left);
       int rH=findH(root->right);
       if(lH==-1||rH==-1){
           return -1;
       }
       int height=1+max(lH,rH);
        if(abs(lH-rH)<=1){
            return height;
        }
        else return -1;
   }


    bool isBalanced(TreeNode* root) {
        if(findH(root)==-1){
            return false;
        }
        return true;
    }
};