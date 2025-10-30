class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagCheck;
    unordered_map<int,bool> upperDiagCheck;
    void storeSolution(vector<vector<string>> &ans,vector<vector<char>> &board,int n){
        vector<string> tempans;
        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            tempans.push_back(output);
        }
        ans.push_back(tempans);
    }
    bool isSafe(int row,int col,vector<vector<char>> &board){
        if(rowCheck[row]==true) return false;
        if(upperDiagCheck[row-col]==true) return false;
        if(lowerDiagCheck[row+col]==true) return false;
        return true;
    }
    void solve(int n,vector<vector<char>> &board ,vector<vector<string>> &ans , int col){
        if(col>=n){
            storeSolution(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                rowCheck[row]= true;
                upperDiagCheck[row-col]= true;
                lowerDiagCheck[row+col]= true;
                //recursion
                solve(n,board,ans,col+1);
                //backtrackking
                board[row][col]='.';
                rowCheck[row]= false;
                upperDiagCheck[row-col] = false;
                lowerDiagCheck[row+col] = false;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       int col = 0;
       vector<vector<char>> board(n,vector<char>(n,'.'));
       solve(n,board,ans,col);
       return ans; 
    }
};