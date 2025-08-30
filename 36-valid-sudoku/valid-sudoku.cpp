class Solution {
public:
    bool validBox(vector<vector<char>>& board, int sr, int er, int sc, int ec){
        // 3x3 box
        unordered_set<char> st;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false; // ✅ fixed
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate Rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()) return false; // ✅ fixed
                st.insert(board[row][col]);
            }
        }

        // Validate Columns
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()) return false; // ✅ fixed
                st.insert(board[row][col]);
            }
        }

        // Validate 3x3 Boxes
        for(int sr = 0; sr < 9; sr += 3){
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc += 3){
                int ec = sc + 2;
                if(!validBox(board, sr, er, sc, ec)) return false;
            }
        }

        return true;
    }
};
