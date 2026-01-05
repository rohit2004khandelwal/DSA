class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        vector<vector<int>> answer(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefix[i][j] = mat[i][j];
                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        //Answer Loop
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int r1 = max(0, i-k);
                int r2 = min(n-1, i+k);
                int c1 = max(0, j-k);
                int c2 = min(m-1, j+k);

                int sum = prefix[r2][c2];

                if(r1 > 0) sum -= prefix[r1-1][c2];
                if(c1 > 0) sum -= prefix[r2][c1-1];
                if(r1 > 0 && c1 > 0) sum += prefix[r1-1][c1-1];
                answer[i][j] = sum;
            }
        }
        return answer;
    }
};