class Solution {
public:
    bool isvalid_sudoku(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col] == c){
                return false;
            }
            if(board[row][i] == c){
                return false;
            }
            if(board[(row/3)*3+(i/3)][(col/3)*3+(i%3)] == c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int row,int col){
        if(col == 9){
            col = 0;
            row++;
            if(row == 9){
                return true;
            }
        }
        if(board[row][col] != '.'){
            return solve(board,row,col+1);
        }
        for(char i='1';i<='9';i++){
            if(isvalid_sudoku(board,row,col,i)){
                board[row][col] = i;
                if(solve(board,row,col+1)){
                    return true;
                }else{
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};
