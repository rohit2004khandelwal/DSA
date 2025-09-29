class Solution {
public:
    int solve(vector<int>& values, int i, int j){
        if(j-i+1<3){
            return 0;
        }
        int result = INT_MAX;
        for(int k=i+1; k<j; k++){
            int wt = values[i] * values[k] * values[j] + solve(values, i, k) + solve(values, k, j);
            result = min(result, wt);
        }
        return result;
    }
    //DP
    int solveMem(vector<int>& values, int i, int j, vector<vector<int>>&dp){
        if(j-i+1<3){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int result = INT_MAX;
        for(int k=i+1; k<j; k++){
            int wt = values[i] * values[k] * values[j] + solveMem(values, i, k, dp) + solveMem(values, k, j, dp);
            result = min(result, wt);
        }
        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // return solve(values, 0, n-1);
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveMem(values, 0, n-1, dp);
    }
};