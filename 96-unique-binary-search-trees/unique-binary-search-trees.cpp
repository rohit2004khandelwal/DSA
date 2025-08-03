class Solution {
public: 
    int solveRec(int n){
        if(n <= 1) return 1;
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solveRec(i-1) * solveRec(n-i);
        }
        return ans;
    }
    //TOP down
    int solveMem(int n, vector<int> &dp){
        if(n <= 1) return 1;
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solveMem(i-1, dp) * solveMem(n-i, dp);
        }
        dp[n] = ans;
        return dp[n];
    }
    int numTrees(int n) {
        // return solveRec(n);
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};