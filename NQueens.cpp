class Solution {
public:
    bool isValidPosition(vector<string> &board,int n,int r,int c){
        for(int i=0;i<r;i++){
            if(board[i][c]=='Q'){
                return false;
            }
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void PossibleSolutions(vector<vector<string>> &v,vector<string> &board,int row,int n){
        if(row==n){
            v.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValidPosition(board,n,row,col)){
                board[row][col]='Q';
                PossibleSolutions(v,board,row+1,n);
                board[row][col]='.';
            }else{
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> v;
        PossibleSolutions(v,board,0,n);
        return v;
    }
};
