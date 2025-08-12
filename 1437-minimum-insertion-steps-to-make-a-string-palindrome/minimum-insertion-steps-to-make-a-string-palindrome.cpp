class Solution {
public:
    int solveRec(string &s, int i, int j){
        if(i>=j) return 0;
        //RECURSION
        if(s[i] == s[j]){
            return solveRec(s, i+1, j-1);
        }
        else{
            return 1 + min(solveRec(s, i+1, j), solveRec(s, i, j-1));
        }
    }
    //TOP DOWN
    int solveMem(string &s, int i, int j, vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //RECURSION
        int ans = 0;
        if(s[i] == s[j]){
            ans = solveMem(s, i+1, j-1, dp);
        }
        else{
            ans = 1 + min(solveMem(s, i+1, j, dp), solveMem(s, i, j-1, dp));
        }
        return dp[i][j] = ans;
    }
    //BOTTOM UP
    int solveTab(string &s){
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<=s.size()-1;j++){
                int ans = 0;
                if(s[i] == s[j]){
                    ans = dp[i+1][j-1];
                }
                else{
                    ans = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][s.size()-1];
    }
    int minInsertions(string s) {
        // return solveRec(s, 0, s.size()-1);
        // vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        // return solveMem(s, 0, s.size()-1, dp);
        return solveTab(s);
    }
};