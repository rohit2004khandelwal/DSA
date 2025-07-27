class Solution {
public:
    int solveRec(int n){
        // base case
        if(n == 0) return 0;
        if(n<0) return 0;
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + solveRec(n-perfectSquare);
            if(numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
            i++;
        }
        return ans;
    }
    //TOP DOWN
    int solveMem(int n, vector<int> &dp){
        // base case
        if(n == 0) return 0;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + solveMem(n-perfectSquare, dp);
            if(numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
            i++;
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        // return solveRec(n);
        vector<int> dp(n+1, -1);
        return solveMem(n,dp);
    }
};
