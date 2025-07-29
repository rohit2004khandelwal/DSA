class Solution {
public:
    bool solve(string &s, int i, int j){
        if(i >= j) return true;//BASE CASE
        //MAIN
        if(s[i] == s[j]) return solve(s, i+1, j-1);
        return false;
    }
    //TOP DOWN
     bool solveMem(string &s, int i, int j, vector<vector<int>> &dp){
        if(i >= j) return true;//BASE CASE
        if(dp[i][j] != -1) return dp[i][j];
        //MAIN
        bool ans;
        if(s[i] == s[j]) ans = solveMem(s, i+1, j-1, dp);
        else ans = false;
        return dp[i][j] = ans;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int maxLen = 0;
        int sp = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solveMem(s, i, j, dp) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};