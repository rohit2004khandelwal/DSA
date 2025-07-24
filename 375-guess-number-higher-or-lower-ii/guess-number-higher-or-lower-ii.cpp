class Solution {
public:
    int solveRec(int s, int e){
        //base case
        if(s>=e) return 0;
        //recursion
        int ans = INT_MAX;
        for(int i=s;i<e;i++){
            ans = min(ans, i + max(solveRec(s,i-1), solveRec(i+1, e)));
        }
        return ans;
    }
    //TOP DOWN
    int solveMem(int s, int e, vector<vector<int>>& dp){
        //base case
        if(s>=e) return 0;
        //recursion
        if(dp[s][e] != -1) return dp[s][e];
        int ans = INT_MAX;
        for(int i=s;i<e;i++){
            ans = min(ans, i + max(solveMem(s,i-1,dp), solveMem(i+1, e,dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    //BOTTOM UP
    int solveTab(int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));//PEHLE HI SAB ZERO KAR DIYA SO NO NEED TO WORRY ABOUT BASE CASE
        //recursion
        // if(dp[s][e] != -1) return dp[s][e];
        for(int s=n;s>=1;s--){
            for(int e=1;e<=n;e++){
                if(s>=e) continue;
                else{
                    int ans = INT_MAX;
                    for(int i=s;i<e;i++){
                        ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // return solveRec(1,n);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(1,n,dp);
        return solveTab(n);
    }
};