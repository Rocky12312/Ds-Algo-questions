class Solution {
public:
    void permute(int i, int j, vector<int> nums, vector<vector<int>> &ans, vector<int> comb) {
        if (i == nums.size()) {
            ans.push_back(comb);
            return;
        }
        for(int k = j; k > 0; k--) {
            int tmp = nums[k];
            nums[k] = nums[k-1];
            nums[k-1] = tmp;
        }
        for(int k = i; k < nums.size(); k++) {
            comb[i] = nums[k];
            permute(i+1, k, nums, ans, comb);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> combination(nums.size());
        permute(0, 0, nums, answer, combination);
        return answer;   
    }
};

