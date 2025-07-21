class Solution {
public:
    long long int mod = 1000000007;
    int solveRec(int n, int k, int target){
        // base
        if(target < 0 || n < 0) return 0;  //dhyan rkhna
        if(n == 0 && target == 0) return 1;
        if(n == 0 and target != 0) return 0;
        if(n != 0 && target == 0) return 0;
        
        // recursion logic
        int ans = 0;
        for(int i = 1; i<=k;i++){
            ans += solveRec(n-1,k,target-i);
        }
        return ans;
    }
    long long int solveMem(int n, int k, int target, vector<vector<long long int>>&dp){
        if(target < 0 || n < 0) return 0;  //dhyan rkhna
        if(n == 0 && target == 0) return 1;
        if(n == 0 and target != 0) return 0;
        if(n != 0 && target == 0) return 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        // recursion logic
        long long int ans = 0;
        for(int i = 1; i<=k;i++){
            ans += solveMem(n-1,k,target-i,dp) % mod;
        }
        dp[n][target] = ans%mod;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n,k,target);
        vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,-1));
        return solveMem(n,k,target,dp);

    }
};