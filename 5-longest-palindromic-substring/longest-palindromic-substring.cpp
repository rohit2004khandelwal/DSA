class Solution {
public:
    bool solve(string &s, int i, int j){
        if(i >= j) return true;//BASE CASE
        //MAIN
        if(s[i] == s[j]) return solve(s, i+1, j-1);
        return false;
    }
    //TOP DOWN
     bool solveMem(string &s, int i, int j, vector<vector<int>> &dp){
        if(i >= j) return true;//BASE CASE
        //MAIN
        if(s[i] == s[j]) return solveMem(s, i+1, j-1, dp);
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int maxLen = INT_MIN;
        int sp = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(solveMem(s, i, j, dp) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};