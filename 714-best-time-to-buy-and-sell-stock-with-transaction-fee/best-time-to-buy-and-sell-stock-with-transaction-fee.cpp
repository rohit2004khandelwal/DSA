class Solution {
public:
    //USING 2 CODE AS MULTIPLE TIMES ALLOWED
    int solveSO(vector<int>& prices, int fee){
        // vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[i] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[i] + next[1] - fee;
                    int skipkaro = 0 + next[0];
                    profit = max(sellKaro, skipkaro);
                }
                curr[buy] = profit;
            }
            next = curr;//SHIFTING
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveSO(prices, fee);
    }
};