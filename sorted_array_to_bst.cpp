class Solution {
public:
    TreeNode* bst(vector<int> &nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int mid = (left+((right-left)/2));
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = bst(nums,left,mid-1);
        temp->right = bst(nums,mid+1,right);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        return bst(nums,0,nums.size()-1);
    }
};

