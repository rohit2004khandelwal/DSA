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
    //BOTTOM UP
    int solveTab(int n){
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++){
        int ans = INT_MAX;
        int start = 1;
        int end = sqrt(i);
        while(start <= end){
            int perfectSquare = start * start;
            int numberOfPerfectSquares = 1 + dp[i-perfectSquare];
            if(numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
            start++;
        }
        dp[i] = ans;
        }
        return dp[n];
    }
    int numSquares(int n) {
        // return solveRec(n);
        // vector<int> dp(n+1, -1);
        // return solveMem(n,dp);
        return solveTab(n);
    }
};
