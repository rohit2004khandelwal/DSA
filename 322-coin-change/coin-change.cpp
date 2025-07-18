class Solution {
public:
    //RECURSION 
    int solve(vector<int>& coins, int amount){
        //BASE CASE
        if(amount == 0) return 0;
        int minCoin = INT_MAX;
        //1 case hum baki recursion
        for(int i=0;i<coins.size();i++){
            int coin = coins[i];
            if(coin<=amount){
                int recAns = solve(coins, amount-coin);
                if(recAns != INT_MAX){
                    int coinUsed = 1+recAns;
                    minCoin = min(minCoin, coinUsed);
                }
            }
        }
        return minCoin;
    }

    //DP(TOP DOWN):-
    int solveMem(vector<int>& coins, int amount, vector<int>&dp){
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int minCoin = INT_MAX;
        //1 case hum baki recursion
        for(int i=0;i<coins.size();i++){
            int coin = coins[i];
            if(coin<=amount){
                int recAns = solveMem(coins, amount-coin, dp);
                if(recAns != INT_MAX){
                    int coinUsed = 1+recAns;
                    minCoin = min(minCoin, coinUsed);
                }
            }
        }
        dp[amount]= minCoin;
        return dp[amount];
    }
    //DP(BOTTOM UP):-
    int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int amt=1;amt<=amount;amt++){
            int minCoin = INT_MAX;
            for(int i=0;i<coins.size();i++){
            int coin = coins[i];
            if(coin<=amt){
                int recAns = dp[amt-coin];
                if(recAns != INT_MAX){
                    int coinUsed = 1+recAns;
                    minCoin = min(minCoin, coinUsed);
                }
            }
        }
        dp[amt]= minCoin;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins, amount);
        vector<int> dp(amount+1,-1);
        // int ans = solveMem(coins, amount, dp);
        int ans = solveTab(coins, amount);
        if(ans == INT_MAX) {
            return -1;
        }else{
            return ans;
        }
    }
};