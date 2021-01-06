class Solution {
public:
    TreeNode* increasingBST(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        if(root->left == nullptr){
            root->right = increasingBST(root->right);
            return root;
        }
        TreeNode* node = root->left;
        root->left = node->right;
        node->right = root;
        return increasingBST(node);
    }
};
