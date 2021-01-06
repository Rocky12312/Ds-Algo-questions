class Solution {
public:
    TreeNode* solve(vector<int>& postorder,int start,int end,int &p_index,unordered_map<int,int>&um){
        if(start>end){
            return nullptr;
        }
        TreeNode*root = new TreeNode(postorder[p_index--]);
        int index = um[root->val];
        root->right = solve(postorder,index+1,end,p_index,um);
        root->left = solve(postorder,start,index-1,p_index,um);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> um;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            um[inorder[i]] = i;
        }
        int p_index = n-1;
        return solve(postorder,0,n-1,p_index,um);
    }
};
