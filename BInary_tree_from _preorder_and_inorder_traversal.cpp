class Solution {
public:
    TreeNode* solve(vector<int>& preorder,int start,int end,int &p_index,unordered_map<int,int>&um){
        if(start>end){
            return nullptr;
        }
        TreeNode*root = new TreeNode(preorder[p_index++]);
        int index = um[root->val];
        root->left = solve(preorder,start,index-1,p_index,um);
        root->right = solve(preorder,index+1,end,p_index,um);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> um;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            um[inorder[i]] = i;
        }
        int p_index = 0;
        return solve(preorder,0,n-1,p_index,um);
    }
};
