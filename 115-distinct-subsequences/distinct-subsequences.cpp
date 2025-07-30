class Solution {
public:
    int solveRec(string& s, string& t, int i, int j) {
        // BASE CASE
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;
        // MAIN
        int ans = 0;
        if (s[i] == t[j]) {
            ans += solveRec(s, t, i + 1, j + 1);
        }
        ans += solveRec(s, t, i + 1, j);
        return ans;
    }
    // TOP DOWN
    int solveMem(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        // BASE CASE
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        // MAIN
        int ans = 0;
        if (s[i] == t[j]) {
            ans += solveMem(s, t, i + 1, j + 1, dp);
        }
        ans += solveMem(s, t, i + 1, j, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    // BOTTOM UP
    int solveTab(string& s, string& t) {
        vector<vector<double>> dp(s.length() + 1, vector<double>(t.length() + 1, 0));
        // BASE CASE ANALYSIS
        for (int i = 0; i <= s.length(); i++) {
            dp[i][t.length()] = 1;
        }
        // MAIN LOGIC
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = t.length() - 1; j >= 0; j--) {
                double ans = 0.0;
                if (s[i] == t[j]) {
                    ans += dp[i + 1][j + 1];
                }
                ans += dp[i+1][j];
                dp[i][j] = ans;
            }
        }
        return (int)dp[0][0];
    }
    int numDistinct(string s, string t) {
        // return solveRec(s, t, 0, 0);
        // vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
        // return solveMem(s, t, 0, 0, dp);
        return solveTab(s, t);
    }
};