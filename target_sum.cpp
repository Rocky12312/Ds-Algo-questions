class Solution {
public:
    //stbf--sum to be found
    //sum to be found = (sum+S)/2 if and only if (sum+s)%2==0
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int zeros = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            if(nums[i] == 0){
                zeros++;
            }
        }
        if(S>sum){
            return 0;
        }
        int stbf = (sum+S)/2;
        if((sum+S)%2!=0){
            return 0;
        }
        int ax[nums.size()+1][stbf+1];
        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<stbf+1;j++){
                if(i == 0){
                    ax[i][j] = 0;
                }
                if(j == 0){
                    ax[i][j] = 1;
                }
            }
        }
        for(int i=1;i<nums.size()+1;i++){
            for(int j=1;j<stbf+1;j++){
                if(nums[i-1]==0){
                    ax[i][j] = ax[i-1][j];
                }else if(nums[i-1]<=j){
                    ax[i][j] = ax[i-1][j]+ax[i-1][j-nums[i-1]];
                }else{
                    ax[i][j] = ax[i-1][j];
                }
            }
        }
        return pow(2,zeros)*ax[nums.size()][stbf];
    }
};
