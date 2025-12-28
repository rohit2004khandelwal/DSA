class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        int count = 0;
        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                if(grid[i][j] < 0){
                    count++;
                }
            }
        }
        return count;
    }
};