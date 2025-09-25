class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == triangle.size() - 1)
            return triangle[row][col];
        int down = triangle[row][col] + solve(triangle, row + 1, col);
        int plus = triangle[row][col] + solve(triangle, row + 1, col + 1);
        return min(down, plus);
    }
    //TOP DOWN
    int solveMem(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
        if (row == triangle.size() - 1)
            return triangle[row][col];
        if (dp[row][col] != INT_MAX) 
            return dp[row][col];
        
        int down = triangle[row][col] + solveMem(triangle, row + 1, col, dp);
        int plus = triangle[row][col] + solveMem(triangle, row + 1, col + 1, dp);
        
        return dp[row][col] = min(down, plus);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(triangle, 0, 0);
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); 
        return solveMem(triangle, 0, 0, dp);
    }
};

// class Solution {
// public:
//     int t[201][201];
//     int n;
//     int solve(vector<vector<int>>& triangle, int row, int col) {
//         if (row == n-1)
//             return triangle[row][col];

//         if(t[row][col] != INT_MAX)
//             return t[row][col];
        
//         int minPath = triangle[row][col] + 
//                       min(solve(triangle, row + 1, col),
//                           solve(triangle, row + 1, col + 1));

//         return t[row][col] = minPath;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
       
//         for (int i = 0; i < 201; i++) {
//             for (int j = 0; j < 201; j++) {
//                 t[i][j] = INT_MAX;
//             }
//         }
//         return solve(triangle, 0, 0);
//     }
// };
