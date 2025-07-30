class Solution {
public: 
    unordered_set<string> st;
    int n;
    bool solveRec(string &s, int idx){
        //BASE CASE
        if(idx == n) return true;
        if(st.find(s) != st.end()) return true;
        //MAIN LOGIC
        for(int l=1;l<=n;l++){
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solveRec(s, idx+l)){
                return true;
            }
        }
        return false;
    }
    //TOP DOWN
    bool solveMem(string &s, int idx, vector<int> &dp){
        //BASE CASE
        if(idx == n) return true;
        if(st.find(s) != st.end()) return true;

        if(dp[idx] != -1) return dp[idx];
        //MAIN LOGIC
        for(int l=1;l<=n;l++){
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solveMem(s, idx+l, dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(string &word : wordDict) {
            st.insert(word);
        }
        // return solveRec(s, 0);
        vector<int> dp(n+1, -1);
        return solveMem(s, 0, dp);
    }
};