class Solution {
public:
    int solveRec(int i, int buy, vector<int>& prices){
        if(i >= prices.size()) return 0;
        int profit = 0;
        if(buy){
            int buyKaro = -prices[i] + solveRec(i+1, 0, prices);
            int skipKaro = 0 + solveRec(i+1, 1, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[i] + solveRec(i+1, 1, prices);
            int skipkaro = 0 + solveRec(i+1, 0, prices);
            profit = max(sellKaro, skipkaro);
        }
        return profit;
    }
    //TOP DOWN
    int solveMem(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            int buyKaro = -prices[i] + solveMem(i+1, 0, prices, dp);
            int skipKaro = 0 + solveMem(i+1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[i] + solveMem(i+1, 1, prices, dp);
            int skipkaro = 0 + solveMem(i+1, 0, prices, dp);
            profit = max(sellKaro, skipkaro);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // return solveRec(0, 1, prices);
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        return solveMem(0, 1, prices, dp);
    }
};