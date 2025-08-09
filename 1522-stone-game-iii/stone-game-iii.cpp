class Solution {
public:
    int solveRec(vector<int>& stoneValue, int i){
         if(i == stoneValue.size()) return 0;
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1; X <= 3; X++){ // X: how many stone picked
            if(i + X - 1 >= stoneValue.size()) break;
            total += stoneValue[i + X - 1];
            ans = max(ans, total - solveRec(stoneValue, i + X));
        }
        return ans;
    }
    //TOP DOWN
    int solveMem(vector<int>& stoneValue, int i, vector<int> &dp){
         if(i == stoneValue.size()) return 0;
         if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1; X <= 3; X++){ // X: how many stone picked
            if(i + X - 1 >= stoneValue.size()) break;
            total += stoneValue[i + X - 1];
            ans = max(ans, total - solveMem(stoneValue, i + X, dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // int ans = solveRec(stoneValue, 0);//A-B
        vector<int> dp(stoneValue.size()+1, -1);
        int ans = solveMem(stoneValue, 0, dp);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};