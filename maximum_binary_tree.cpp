class Solution {
public:
    TreeNode* solve(vector<int>& nums,int a,int b){
        if(a>b){
            return NULL;
        }
        int max_index = a;
        for(int i=a;i<=b;i++){
            if(nums[i]>nums[max_index]){
                max_index = i;
            }
        }
        TreeNode*root = new TreeNode(nums[max_index]);
        root->left = solve(nums,a,max_index-1);
        root->right = solve(nums,max_index+1,b);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        TreeNode*pop = NULL;
        pop = solve(nums,0,nums.size()-1);
        return pop;
    }
};
