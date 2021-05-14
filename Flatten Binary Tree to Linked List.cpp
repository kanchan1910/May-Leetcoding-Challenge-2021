
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL || (root->left == NULL && root->right == NULL))
        {
            // already flatten
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode* right_subtree = root->right;
       
        root->right = root->left;
        root->left = NULL;
        TreeNode* tail;
        if(root->right != NULL)
        {
             tail = root->right;
        }
        else
        {
             tail = root;
        }
        while(tail->right != NULL)
        {
            tail = tail->right;
        }
        tail->right = right_subtree;
    }
};
