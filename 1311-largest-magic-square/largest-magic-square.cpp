class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c, int k){
        int s = 0;

        for(int j=c; j<c+k; j++) s+= grid[r][j];

        for(int i=r; i<r+k; i++){
            int sum = 0;
            for(int j=c; j<c+k; j++)
                sum += grid[i][j];
            if(sum != s) return false;
        }

        for(int j=c; j<c+k; j++){
            int sum = 0;
            for(int i=r; i<r+k; i++)
                sum += grid[i][j];
            if(sum != s) return false;
        }
        int d1 = 0;
        for(int i=0; i<k; i++){
            d1 += grid[r+i][c+i];
        }
        if(d1 != s) return false;

        int d2 = 0;
        for(int i=0; i<k; i++){
            d2 += grid[r+i][c+k-1-i];
        }
        if(d2 != s) return false;

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxK = min(m, n);

        for(int k=maxK; k>=2; k--){
            for(int i=0; i+k<=m; i++){
                for(int j=0; j+k<=n; j++){
                    if(isMagic(grid, i, j, k)){
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};