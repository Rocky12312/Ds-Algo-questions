class Solution {
public:
    void solve(vector<vector<int>> &matrix, vector<vector<int>> &ax,int i,int j,int &r,int &c) {
        ax[i][j] = 1;
        if (i-1 >= 0 && matrix[i][j] < matrix[i - 1][j]){
            if(ax[i-1][j] == -1){
                solve(matrix, ax, i - 1, j, r, c);
            }
            ax[i][j] = max(ax[i][j],ax[i-1][j]+1);
        }
        if(i+1 < r && matrix[i][j] < matrix[i+1][j]) {
            if(ax[i+1][j] == -1){
                solve(matrix, ax, i + 1, j, r, c);
            }
            ax[i][j] = max(ax[i][j],ax[i+1][j]+1);
        }
        
        if(j-1 >= 0 && matrix[i][j] < matrix[i][j - 1]) {
            if(ax[i][j-1] == -1){
                solve(matrix,ax,i,j-1,r,c);
            }
            ax[i][j] = max(ax[i][j],ax[i][j-1]+1);
        }
        if(j+1 < c && matrix[i][j] < matrix[i][j+1]) {
            if(ax[i][j+1] == -1){
                solve(matrix,ax,i,j+1,r,c);
            }
            ax[i][j] = max(ax[i][j],ax[i][j+1]+1);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        if(r==0 || c==0){
            return 0;
        }
        int res = 0;
        vector<vector<int>> ax(r, vector<int>(c,-1));
        for (int i = 0;i < r;++i){
            for (int j = 0;j < c;++j){
                if(dp[i][j] == -1){
                    solver(matrix,ax,i,j,r,c);
                }
                res = max(res,ax[i][j]);
            }
        }
        return res;
    }
};

