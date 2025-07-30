class Solution {
public: 
    int solveRec(string &s, string &t, int i, int j){
        //BASE CASE
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        //MAIN 
        int ans = 0;
        if(s[i] == t[j]){
            ans += solveRec(s, t, i+1, j+1);
        }
        ans += solveRec(s, t, i+1, j);
        return ans;
    }
    //TOP DOWN
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        //BASE CASE
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //MAIN 
        int ans = 0;
        if(s[i] == t[j]){
            ans += solveMem(s, t, i+1, j+1, dp);
        }
        ans += solveMem(s, t, i+1, j, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        // return solveRec(s, t, 0, 0);
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
        return solveMem(s, t, 0, 0, dp);
    }
};