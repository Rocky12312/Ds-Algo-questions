class Solution {
public:
   void dfs(int i,int j,int r,int c,vector<vector<char>>& board){   
       if(i<0||j<0||i>=r||j>=c || board[i][j] == 'X'){
           return;
       }
       if(board[i][j]=='O'){
           board[i][j]='1';
           dfs(i+1,j,r,c,board);
           dfs(i-1,j,r,c,board);
           dfs(i,j+1,r,c,board);
           dfs(i,j-1,r,c,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r==0){
            return;
        }
        int c=board[0].size();
        for(int i=0;i<r;i++){   
            dfs(i,0,r,c,board);
            dfs(i,c-1,r,c,board);
        }
        for(int j=0;j<c;j++){   
            dfs(0,j,r,c,board);
            dfs(r-1,j,r,c,board);
        }
        for(int i=0;i<r;i++){   
            for(int j=0;j<c;j++){   
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }
    }
};

