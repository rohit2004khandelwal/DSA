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
    int maxProfit(int k, vector<int>& prices) {
        return solveTabSO(prices, k);
    }
};