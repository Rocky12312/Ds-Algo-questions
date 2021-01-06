class Solution {
public:
    int fsum = 0;
    vector<int> v;
    int postorder(TreeNode*root){
        if(root == NULL){
            return 0;
        }
        int leftsum = postorder(root->left);
        int rightsum = postorder(root->right);
        int fsum = abs(leftsum - rightsum);
        v.push_back(fsum);
        return root->val+leftsum+rightsum;
    }
    int findTilt(TreeNode* root) {
        int p = postorder(root);
        for(int i=0;i<v.size();i++){
            fsum += v[i];
        }
        return fsum;
    }
};
