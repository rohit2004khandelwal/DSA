class Solution {
public:
    int solveRec(vector<int>& piles, int i, int M, int aliceTurn){
        if(i == piles.size()) return 0;
        int ans = aliceTurn ? INT_MIN : INT_MAX;
        int total = 0;
        for(int X = 1; X <= 2 * M; X++){
            if(i + X - 1 >= piles.size()) break;
            total += piles[i + X - 1];
            if(aliceTurn) ans = max(ans, total + solveRec(piles, i + X, max(X, M), !aliceTurn));
            else ans = min(ans, solveRec(piles, i + X, max(X, M), !aliceTurn));
        }
        return ans;
    }
    //TOP DOWN
    int solveMem(vector<int>& piles, int i, int M, int alice, vector<vector<vector<int>>> &dp){
        if(i == piles.size()) return 0;//BASE CASE
        if(dp[i][M][alice] != -1) return dp[i][M][alice];
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
        for(int X = 1; X <= 2 * M; X++){
            if(i + X - 1 >= piles.size()) break;
            total += piles[i + X - 1];
            if(alice) ans = max(ans, total + solveMem(piles, i + X, max(X, M), !alice, dp));
            else ans = min(ans, solveMem(piles, i + X, max(X, M), !alice, dp));
        }
        return dp[i][M][alice] = ans;
    }
    //BOTTOM UP
    int solveTab(vector<int>& piles){
        vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2, 0)));
        for(int i=piles.size()-1;i>=0;i--){
            for(int M=piles.size();M>=1;M--){
                for(int alice=0;alice<=1;alice++){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;
                    for(int X = 1; X <= 2 * M; X++){
                        if(i + X - 1 >= piles.size()) break;
                        total += piles[i + X - 1];
                        if(alice) ans = max(ans, total + dp[i + X][max(X, M)][!alice]);
                        else ans = min(ans, dp[i + X][max(X, M)][!alice]);
                    }
                    dp[i][M][alice] = ans;
                }
            }
        }
        return dp[0][1][true];
    }
    int stoneGameII(vector<int>& piles) {
        // return solveRec(piles, 0, 1, true);
        //3D DP USED HERE
        // vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2, -1)));
        // return solveMem(piles, 0, 1, true, dp);
        return solveTab(piles);
    }
};