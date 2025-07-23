class Solution {
public:
    int solveRec(string text1, string text2, int i, int j){
        //BASE CASE
        if(i >= text1.length()) return 0;
        if(j >= text2.length()) return 0;
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solveRec(text1, text2, i+1, j+1);//be carefull about i++ vs i+1 learn more about this on gpt
            //i++ :-  modifies the value of i after passing the old value ,  i gets incremented globally in the current call, affecting other recursive calls
            //i+1 :- does not change the value of i, Just passes the incremented value to the recursive call.
        }else{
            ans = 0 + max(solveRec(text1,text2,i+1,j) , solveRec(text1,text2,i,j+1));
        }
        return ans;
    }
    //TOP DOWM
    int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){  //yaha par text1, text2 ko by reference pass karna hoga kyuki bht sari copies ban jayegi 
        //jiski wajah se tle aayega 
        //BASE CASE
        if(i >= text1.length()) return 0;
        if(j >= text2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solveMem(text1, text2, i+1, j+1, dp);
        }else{
            ans = 0 + max(solveMem(text1,text2,i+1,j, dp) , solveMem(text1,text2,i,j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    //BOTTOM UP
    int solveTab(string text1, string text2){
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        //BASE CASE:- KYUKI HAM PEHLI HI SAB O KAR CHUKE HIA TOH BAAR BAAR LIKHNE KI JARURAT NHI AAYEGA DP MAI -1 LIKHTE TOH 
        //BASE CASE ALAG SE HANDLE KARNA PADTA AS WE DO IN MOSTLY QUES
        int ans = 0;
        //  i -> 0 to text1.length;
        //  j -> 0 to text2.length;
        for(int i = text1.length()-1; i>=0;i--){
            for(int j = text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{ // no match
                    ans = 0 + max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];//FOR THIS CHECK RECURSION CALL WE PASS I AND J BOTH 0
    }
    //SPACE OPT
    int solveTabSO(string text1, string text2){
        // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        //BASE CASE:- KYUKI HAM PEHLI HI SAB O KAR CHUKE HIA TOH BAAR BAAR LIKHNE KI JARURAT NHI AAYEGA DP MAI -1 LIKHTE TOH 
        //BASE CASE ALAG SE HANDLE KARNA PADTA AS WE DO IN MOSTLY QUES
        vector<int> prev(text2.length()+1);
        vector<int> curr(text2.length()+1);
        //  i -> 0 to text1.length;
        //  j -> 0 to text2.length;
        for(int i = text1.length()-1; i>=0;i--){
            for(int j = text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + prev[j+1];
                }
                else{ // no match
                    ans = 0 + max(prev[j],curr[j+1]);
                }
                curr[j] = ans;
            }
            prev = curr;//SHIFTING
        }
        return prev[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        // return solveRec(text1, text2, i, j);
        // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // return solveMem(text1, text2, i, j, dp);
        // return solveTab(text1, text2);
        return solveTabSO(text1, text2);
    }
};