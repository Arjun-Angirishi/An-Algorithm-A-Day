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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int sz=q.size();
            pair<TreeNode*,pair<int,int>> node=q.front();
            int row=node.second.second;
            int col=node.second.first;
            q.pop();
            if(node.first->left!=NULL){
                q.push({node.first->left,{col-1,row+1}});
            }
            if(node.first->right!=NULL){
                q.push({node.first->right,{col+1,row+1}});
            }
            m[col][row].insert(node.first->val);
        }
        for(auto p:m){
            vector<int> l;
            for(auto z: p.second){
                l.insert(l.end(),z.second.begin(),z.second.end());
            }
            ans.push_back(l);
        }
        return ans;
    }
};