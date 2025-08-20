class Solution {
public:  
     void convertStrsToNumStrs(vector<string>&strs, vector<pair<int, int>>&numStrs){
        for(auto str : strs){
            int zeroes = 0, ones = 0;
            for(auto ch : str){
                if(ch == '0') zeroes++;
                else ones++;
            }
            numStrs.push_back({zeroes, ones});
        }
    }
    int solveRec(vector<pair<int,int>>&numStrs, int i, int m, int n){
        if(i == numStrs.size()) return 0;
        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if(m - zeroes >= 0 && n - ones >= 0) include = 1 + solveRec(numStrs, i + 1, m - zeroes, n - ones);
        exclude = solveRec(numStrs, i + 1, m, n);
        return max(include, exclude);
    }
    int solveTD(vector<pair<int,int>>&numStrs, int i, int m, int n, vector<vector<vector<int>>>&dp){
        if(i == numStrs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if(m - zeroes >= 0 && n - ones >= 0) include = 1 + solveTD(numStrs, i + 1, m - zeroes, n - ones, dp);
        exclude = solveTD(numStrs, i + 1, m, n, dp);
        return dp[i][m][n] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> numStrs;
        convertStrsToNumStrs(strs, numStrs);
        // return solveRec(numStrs, 0, m, n);
        vector<vector<vector<int>>>dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solveTD(numStrs, 0, m, n, dp);
    }
};