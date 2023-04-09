vector<int> preorder(Node *root, int level, vector<int> &v)
    {

        if (root == NULL)
        {
            return v;
        }

        if(v.size()==level){
            v.push_back(root->data);
        }

        preorder(root->left, level + 1, v);
        preorder(root->right, level + 1, v);

        return v;
    }

vector<int> leftView(Node *root)
{
    vector<int> v;
    preorder(root, 0, v);
    return v;
}