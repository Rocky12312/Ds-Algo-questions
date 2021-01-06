class Solution {
public:
    int count =0;
    void solve(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        if(grid[i][j] == '2' || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '2';
        solve(i,j+1,grid);
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    count++;
                    solve(i,j,grid);
                }
            }
        }
        return count;
    }
};
