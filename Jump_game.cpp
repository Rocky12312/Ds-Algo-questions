class Solution {
public:
    bool op = false;
    bool isvalid(int sz,int idx){
        if(idx<=sz){
            return true;
        }
        return false;
    }
    bool solve(vector<int>& nums,int index){
        if(index == nums.size()-1){
            op = true;
            return op;
        }
        for(int i=1;i<=nums[index];i++){
            if(isvalid(nums.size()-1,index+i)){
                if(solve(nums,index+i)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        bool kp = solve(nums,0);
        return kp;
    }
};
