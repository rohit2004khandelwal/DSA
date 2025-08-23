class Solution {
public:
    int solveRec(string &word1, string &word2, int i, int j){
        //BASE CASE
        if(i == word1.length()) return word2.length()-j;
        if(j == word2.length()) return word1.length()-i;
        int ans = 0;
        if(word1[i] == word2[j]){
            return solveRec(word1, word2, i+1, j+1);
        }
        else{
            //INSERT
            int insertAns = 1 + solveRec(word1, word2, i, j+1);
            //DELETE
            int deleteAns = 1 + solveRec(word1, word2, i+1, j);
            //REPLACE
            int replaceAns = 1 + solveRec(word1, word2, i+1, j+1);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
    //TOP DOWN
    int solveMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        //BASE CASE
        if(i == word1.length()) return word2.length()-j;
        if(j == word2.length()) return word1.length()-i;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(word1[i] == word2[j]){
            return solveMem(word1, word2, i+1, j+1, dp);
        }
        else{
            //INSERT
            int insertAns = 1 + solveMem(word1, word2, i, j+1, dp);
            //DELETE
            int deleteAns = 1 + solveMem(word1, word2, i+1, j, dp);
            //REPLACE
            int replaceAns = 1 + solveMem(word1, word2, i+1, j+1, dp);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }
    //BOTTOM UP
    int solveTab(string &word1, string &word2){
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        //BASE CASE ANALYSIS
        for(int j=0;j<word2.length();j++){
            dp[word1.length()][j] = word2.length()-j;
        }
        for(int i=0;i<word1.length();i++){
            dp[i][word2.length()] = word1.length()-i;
        }
        for(int i=word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    //INSERT
                    int insertAns = 1 + dp[i][j+1];
                    //DELETE
                    int deleteAns = 1 + dp[i+1][j];
                    //REPLACE
                    int replaceAns = 1 + dp[i+1][j+1];
                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        // return solveRec(word1, word2, 0, 0);
        // vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // return solveMem(word1, word2, 0, 0, dp);
        return solveTab(word1, word2);
    }
};