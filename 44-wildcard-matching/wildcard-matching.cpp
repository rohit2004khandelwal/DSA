class Solution {
public:
    bool solveRec(string &s, string &p, int i, int j){
        //base case
        if(i == s.length() && j == p.length()) return true; //sare characters match hogye hai
        if(j == p.length()) return false;// pattern khtm hogya, but string khtm nhi hui
        if(i == s.length()){
            // agar sare bache hue characters * hai, then true else false
            for(int k=j;k<p.length();k++){
                if(p[k] != '*') return false;
            }
            // reached here -> sare characters * mile p string me
            return true;
        }
        //MAIN LOGIC:-Match or no match
        if(p[j] == '?' || s[i] == p[j]){ //single character match
            return solveRec(s,p,i+1,j+1);
        }
         else if(p[j] == '*'){
            // * can be empty string, or any character
            return solveRec(s,p,i+1,j) || solveRec(s,p,i,j+1);//(i+1) mai character bna and (j+1) mai empty bna
        }
        else{
            // no match
            return false;
        }

    }
    //TOP DOWN
    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i == s.length() && j == p.length()) return true; //sare characters match hogye hai
        if(j == p.length()) return false;// pattern khtm hogya, but string khtm nhi hui
        if(i == s.length()){
            // agar sare bache hue characters * hai, then true else false
            for(int k=j;k<p.length();k++){
                if(p[k] != '*') return false;
            }
            // reached here -> sare characters * mile p string me
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //MAIN LOGIC:-Match or no match
        bool ans;
        if(p[j] == '?' || s[i] == p[j]){ //single character match
            ans = solveMem(s,p,i+1,j+1,dp);
        }
         else if(p[j] == '*'){
            // * can be empty string, or any character
            ans = solveMem(s,p,i+1,j,dp) || solveMem(s,p,i,j+1,dp);//(i+1) mai character bna and (j+1) mai empty bna
        }
        else{
            // no match
            ans = false;
        }
        dp[i][j] = ans;
        return dp[i][j];

    }
    //BOTTOM UP
    bool solveTab(string& s, string& p, int m, int n){
        vector<vector<int> >dp(m+1, vector<int>(n+1,0));
        dp[m][n] = true;

        for(int col = 0; col < n; col++){
            bool flag = true;
            for(int k = col; k<p.length();k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                bool ans;
                if(p[j] == '?' || s[i] == p[j]){
                    ans =  dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    ans =  dp[i+1][j] || dp[i][j+1];
                }
                else{
                    ans =  false;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    bool isMatch(string s, string p) {
        // bool ans = solveRec(s, p, 0, 0);
        // return ans;
        int m = s.length();
        int n = p.length();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solveMem(s, p, 0, 0, dp);
        return solveTab(s,p,m,n);
    }
};