class Solution {
public: 
    bool solveRec(string &s, string &p, int i, int j){
        //BASE CASE
        if(i == s.length() && j == p.length()) return true;
        if(j == p.length()) return false;
        //MAIN CASE
        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i]==p[j]);
        if(j+1 < p.length() && p[j+1] == '*'){
            bool emptyCase = solveRec(s,p,i,j+2);//jab empty le rhe ho
            bool elementCase = currMatch && solveRec(s,p,i+1,j);//jab preceding element imagine kar rhe ho fir currMatch bhi check karo 
            return emptyCase || elementCase;
        }
        else if(currMatch){
            return solveRec(s,p,i+1,j+1);
        }
        else{
            return false;
        }
    }
    //TOP DOWN
    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i == s.length() && j == p.length()) return true;
        if(j == p.length()) return false;

        if(dp[i][j] != -1) return dp[i][j];
        //MAIN CASE
        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i]==p[j]);
        bool ans;
        if(j+1 < p.length() && p[j+1] == '*'){
            bool emptyCase = solveMem(s,p,i,j+2,dp);//jab empty le rhe ho
            bool elementCase = currMatch && solveMem(s,p,i+1,j,dp);//jab preceding element imagine kar rhe ho fir currMatch bhi check karo 
            ans = emptyCase || elementCase;
        }
        else if(currMatch){
            ans = solveMem(s,p,i+1,j+1,dp);
        }
        else{
            ans = false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    bool solveTab(string&s, string&p, int m, int n){
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        dp[m][n] = true;
        for(int i = m; i>=0;i--){
            for(int j = n-1; j>=0;j--){
                bool currMatch = (i<s.length() && p[j] == '.' || s[i] == p[j]);
                bool ans;
                if(j+1 < p.length() && p[j+1] == '*'){
                    bool emptyCase = dp[i][j+2];
                    bool precElementCase = currMatch && dp[i+1][j];
                    ans = emptyCase || precElementCase;
                }
                else if(currMatch){
                    ans = dp[i+1][j+1];
                }
                else{
                    ans = false;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    //SPACE OPT
    bool solveTabSO(string&s, string&p, int m, int n){
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        next[n] = true;
        for(int i = m; i>=0;i--){
            // if(i==m) curr[n] = true;
            // else curr[n] = false;
            curr[n] = (i==m); //important
            for(int j = n-1; j>=0;j--){
                bool currMatch = (i<s.length()) && (p[j] == '.' || s[i] == p[j]);
                bool ans;
                if(j+1 < p.length() && p[j+1] == '*'){
                    bool emptyCase = curr[j+2];
                    bool precElementCase = currMatch && next[j];
                    ans = emptyCase || precElementCase;
                }
                else if(currMatch){
                    ans = next[j+1];
                }
                else{
                    ans = false;
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    bool isMatch(string s, string p) {
        // return solveRec(s,p,0,0);
        int m = s.length();
        int n = p.length();
        // vector<vector<int>> dp(m+1,vector<int>(n+1, -1));
        // return solveMem(s,p,0,0,dp);
        // return solveTab(s,p,m,n);
        return solveTabSO(s,p,m,n);

    }
};