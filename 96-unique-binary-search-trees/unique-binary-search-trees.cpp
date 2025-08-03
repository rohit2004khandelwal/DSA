class Solution {
public:
    int solveRec(int n) {
        if (n <= 1)
            return 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solveRec(i - 1) * solveRec(n - i);
        }
        return ans;
    }
    // TOP down
    int solveMem(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
        }
        dp[n] = ans;
        return dp[n];
    }
    // BOTTOM UP
    int solveTab(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        // i->no of nodes in memo n is used for no of node
        for (int i = 2; i <= n; i++) { // 2 bcoz 0 and 1 counted in base case
            // j -> root node in memo i is used for root node
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        // return solveRec(n);
        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);
        // return solveTab(n);
        // USING CATALAN NUMBER
        long double ans = 1;
        for (int k = 2; k <= n; k++)
            ans *= (n + k), ans /= k;
        return ans;
    }
};