class Solution {
public:
    int solveRec(vector<int>& days, vector<int>& costs, int n, int i) {
        if (i >= n) return 0;

        // 1 DAY PASS
        int cost1 = costs[0] + solveRec(days, costs, n, i + 1);

        // 7 DAY PASS
        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        int cost7 = costs[1] + solveRec(days, costs, n, j);

        // 30 DAY PASS
        j = i;
        while (j < n && days[j] < days[i] + 30) j++;
        int cost30 = costs[2] + solveRec(days, costs, n, j);

        return min({cost1, cost7, cost30});
    }
    //TOP DOWN
    int solveMem(vector<int>& days, vector<int>& costs, int n, int i, vector<int> &dp) {
        if (i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        // 1 DAY PASS
        int cost1 = costs[0] + solveMem(days, costs, n, i + 1, dp);

        // 7 DAY PASS
        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        int cost7 = costs[1] + solveMem(days, costs, n, j, dp);

        // 30 DAY PASS
        j = i;
        while (j < n && days[j] < days[i] + 30) j++;
        int cost30 = costs[2] + solveMem(days, costs, n, j, dp);

        dp[i] = min({cost1, cost7, cost30});
        return dp[i];
    }
    //BOTTOM UP
    int solveTab(vector<int>& days, vector<int>& costs, int n){
        vector<int> dp(n+1, 0);

        for(int k=n-1;k>=0;k--){
            int cost1 = costs[0] + dp[k + 1];

        // 7 DAY PASS
        int j = k;
        while (j < n && days[j] < days[k] + 7) j++;
        int cost7 = costs[1] + dp[j];

        // 30 DAY PASS
        j = k;
        while (j < n && days[j] < days[k] + 30) j++;
        int cost30 = costs[2] + dp[j];

        dp[k] = min({cost1, cost7, cost30});
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // return solveRec(days, costs, n, 0);
        // vector<int> dp(n+1, -1);
        // return solveMem(days, costs, n, 0, dp);
        return solveTab(days, costs, n);
    }
};
