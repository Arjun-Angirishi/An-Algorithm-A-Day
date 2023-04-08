class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> hp;
        if(root==NULL){
            return ans;
        }
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* node=q.front().first;
            int col=q.front().second;
            q.pop();
            if(node->left!=NULL){
                q.push({node->left,col-1});
            }
            if(node->right!=NULL){
                q.push({node->right,col+1});
            }
            if(hp.find(col)==hp.end()){
                hp[col]=node->data;
            }
        }
        
        for(auto p: hp){
            ans.push_back(p.second);
        }
        return ans;
    }

};