class Solution {
public:
    int count=0;
    void dfs(vector<vector<int>> grid,int i,int j,int c){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2 && c==0){
            count++;
            return;
        }
        if(grid[i][j]==2){
            return;
        }
        grid[i][j]=-1;
        dfs(grid,i,j+1,c-1);
        dfs(grid,i+1,j,c-1);
        dfs(grid,i-1,j,c-1);
        dfs(grid,i,j-1,c-1);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int s_i;
        int s_j;
        int zeros_count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    s_i = i;
                    s_j = j;
                }
                if(grid[i][j] == 0){
                    zeros_count++;
                }
            }
        }
        dfs(grid, s_i, s_j,zeros_count+1);
        return count;
    }
};
