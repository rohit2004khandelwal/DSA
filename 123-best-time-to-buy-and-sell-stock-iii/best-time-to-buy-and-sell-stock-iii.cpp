class Solution {
public:
    int solveRec(int i, int buy, int limit, vector<int>& prices){
        //BASES CASES
        if(i >= prices.size()) return 0;
        if(limit == 0) return 0;
        int profit = 0;
        if(buy){
            int buyKaro = -prices[i] + solveRec(i+1, 0, limit, prices);
            int skipKaro = 0 + solveRec(i+1, 1, limit, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[i] + solveRec(i+1, 1, limit-1, prices);//SELL HONE PAR HI EK TRANSACTION KHTM HOGI ISLIYE SELL PAR LIMIT-1 LARNA HAI
            int skipKaro = 0 + solveRec(i+1, 0, limit, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    //TOP DOWN
    int solveMem(int i, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>> &dp){
        //BASES CASES
        if(i >= prices.size()) return 0;
        if(limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
        int profit = 0;
        if(buy){
            int buyKaro = -prices[i] + solveMem(i+1, 0, limit, prices, dp);
            int skipKaro = 0 + solveMem(i+1, 1, limit, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[i] + solveMem(i+1, 1, limit-1, prices, dp);//SELL HONE PAR HI EK TRANSACTION KHTM HOGI ISLIYE SELL PAR LIMIT-1 LARNA HAI
            int skipKaro = 0 + solveMem(i+1, 0, limit, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // return solveRec(0, 1, 2, prices);
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveMem(0, 1, 2, prices, dp);
    }
};