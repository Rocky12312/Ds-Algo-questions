//solution 1
class Solution {
public:
    bool op = true;
    bool solve(TreeNode* root,long minimum,long maximum){
        if(root==NULL){
            return true;
        }
        if(root->val>minimum && root->val<maximum){
            return solve(root->left,minimum,root->val) && solve(root->right,root->val,maximum);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        op = solve(root,LONG_MIN, LONG_MAX);
        return op;
    }
};
//solution 2
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool issorted = false;
        vector<int> v;
        iotrv(root,v);
        if(v.size() == 0){
            return true;
        }
        issorted = sorting(v);
        return issorted;
    }
    void iotrv(TreeNode*root,vector<int> &v){
        if(root == NULL){
            return;
        }
        iotrv(root->left,v);
        v.push_back(root->val);
        iotrv(root->right,v);
    }
    bool sorting(vector<int> &v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};
