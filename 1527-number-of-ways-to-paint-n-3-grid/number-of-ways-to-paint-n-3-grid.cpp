class Solution {
public:
    int M = 1e9+7;
    string states[12] = {"RYR", "RYG", "RGR", "RGY", "YRY", "YRG", "YGR", "YGY", "GRY", "GRG", "GYR", "GYG"};

    int solveRec(int n, int prev){
        //BASECASE
        if(n == 0) return 1;
        int result = 0;
        string last = states[prev];

        for(int curr=0; curr<12; curr++){
            if(curr == prev) continue;
            string currPat = states[curr];
            bool conflict = false;
            for(int col=0; col<3; col++){
                if(currPat[col] == last[col]){
                    conflict = true;
                    break;
                }
            }
            if(!conflict){
                result = (result + solveRec(n-1, curr)) % M;
            }
        }
        return result;
    }
    //MEMO
    int solveMem(int n, int prev, vector<vector<int>> &dp){
        //BASECASE
        if(n == 0) return 1;
        if(dp[n][prev] != -1) return dp[n][prev];
        int result = 0;
        string last = states[prev];

        for(int curr=0; curr<12; curr++){
            if(curr == prev) continue;
            string currPat = states[curr];
            bool conflict = false;
            for(int col=0; col<3; col++){
                if(currPat[col] == last[col]){
                    conflict = true;
                    break;
                }
            }
            if(!conflict){
                result = (result + solveMem(n-1, curr, dp)) % M;
            }
        }
        return dp[n][prev] = result;
    }

    int numOfWays(int n) {
        int result = 0;
        vector<vector<int>> dp(n+1, vector<int>(12, -1));
        // for(int i=0; i<12; i++){
        //     result = (result + solveRec(n-1, i)) % M;
        // }
        for(int i=0; i<12; i++){
            result = (result + solveMem(n-1, i, dp)) % M;
        }
        return result;
    }
};