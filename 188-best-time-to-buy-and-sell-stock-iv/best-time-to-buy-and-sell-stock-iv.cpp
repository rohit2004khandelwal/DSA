class Solution {
public:
    //SAME AS BUY STOCK |||
    //SPACE OPTIMISATION
    int solveTabSO(vector<int>& prices, int k){
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){ //LIMIT 0 WALA CASE ALREADY HANDLE HO CHUKA HAI
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[i] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = prices[i] + next[1][limit-1];//SELL HONE PAR HI EK TRANSACTION KHTM HOGI ISLIYE SELL PAR LIMIT-1 LARNA HAI
                        int skipKaro = 0 + next[0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][k];
    }
    //USING TRANSACTION NUMBER
    int solve(int i, int optNo, int k, vector<int>& prices){
        if(i == prices.size()) return 0;
        if(optNo == 2*k) return 0;
        int profit = 0;
        if(optNo%2 == 0){
            int buyKaro = -prices[i] + solve(i+1, optNo+1, k, prices);
            int skipKaro = 0 + solve(i+1, optNo, k, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[i] + solve(i+1, optNo+1, k, prices);
            int skipKaro = 0 + solve(i+1, optNo, k, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    //TOP DOWN
    int solveMem(int i, int optNo, int k, vector<int>& prices, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        if(optNo == 2*k) return 0;
        if(dp[i][optNo] != -1) return dp[i][optNo];
        int profit = 0;
        if(optNo%2 == 0){
            int buyKaro = -prices[i] + solveMem(i+1, optNo+1, k, prices, dp);
            int skipKaro = 0 + solveMem(i+1, optNo, k, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[i] + solveMem(i+1, optNo+1, k, prices, dp);
            int skipKaro = 0 + solveMem(i+1, optNo, k, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][optNo] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // return solveTabSO(prices, k);
        // return solve(0, 0, k, prices);
        vector<vector<int>> dp(prices.size()+1, vector<int>(2*k, -1));
        return solveMem(0, 0, k, prices, dp);
    }
};