class Solution {
public:
    int solveRec(string &s1, string &s2, int i, int j){
        //BASE CASE
        if(i >= s1.length() && j >= s2.length()) return 0;
        if(i >= s1.length()){
            return s2[j] + solveRec(s1, s2, i, j+1);
        }
        if(j >= s2.length()){
            return s1[i] + solveRec(s1, s2, i+1, j);
        }
        if(s1[i] == s2[j]) return solveRec(s1, s2, i+1, j+1);
        else{
            int delS1 = s1[i] + solveRec(s1, s2, i+1,j);
            int delS2 = s2[j] + solveRec(s1, s2, i, j+1);
            return min(delS1, delS2);
        }
    }
    //TOP DOWN
    int solveMem(string &s1, string &s2, int i, int j,  vector<vector<int>> &dp){
        //BASE CASE
        int ans;
        if(i >= s1.length() && j >= s2.length()) return 0;
        if(i >= s1.length()){
            return s2[j] + solveMem(s1, s2, i, j+1, dp);
        }
        if(j >= s2.length()){
            return s1[i] + solveMem(s1, s2, i+1, j, dp);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) ans = solveMem(s1, s2, i+1, j+1, dp);
        else{
            int delS1 = s1[i] + solveMem(s1, s2, i+1,j, dp);
            int delS2 = s2[j] + solveMem(s1, s2, i, j+1, dp);
            ans = min(delS1, delS2);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    //BOTTOM UP
    int solveTab(string &s1, string &s2, int i, int j){
        vector<vector<int>> dp(i+1, vector<int>(j+1, 0));
        int ans;
        if(i >= s1.length() && j >= s2.length()) return 0;
        if(i >= s1.length()){
            return s2[j] + solveMem(s1, s2, i, j+1, dp);
        }
        if(j >= s2.length()){
            return s1[i] + solveMem(s1, s2, i+1, j, dp);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) ans = solveMem(s1, s2, i+1, j+1, dp);
        else{
            int delS1 = s1[i] + solveMem(s1, s2, i+1,j, dp);
            int delS2 = s2[j] + solveMem(s1, s2, i, j+1, dp);
            ans = min(delS1, delS2);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        int i = s1.length();
        int j = s2.length();
        // return solveRec(s1, s2, 0, 0);
        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
        return solveMem(s1, s2, 0, 0, dp);
        // return solveTab(s1, s2, 0, 0);
    }
};