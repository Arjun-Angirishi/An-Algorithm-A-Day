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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> s;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){
                q.push(node->left);
                }
                if(node->right!=NULL){
                q.push(node->right);
                }
                s.push_back(node->val);
            }
            v.push_back(s);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};


/**Same question can be solved by using stacks**/