class Solution {
public:
    bool isSafe(vector<int>c1,vector<int>c2){
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]) return true;
        else return false;
    }
    int solveRec(vector<vector<int>>& cuboids, int curr, int prev){
        if(curr >= cuboids.size()) return 0;
        //INCLUDE EXCLUDE LIKE LIS
        int inc = 0;
        if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
            inc = cuboids[curr][2] + solveRec(cuboids, curr+1, curr);
        }
        int exc = 0 + solveRec(cuboids, curr+1, prev);
        int finalAns = max(inc, exc);
        return finalAns;
    }
    //top down
    int solveMem(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>&dp){
        if(curr >= cuboids.size()) return 0;
        //INCLUDE EXCLUDE LIKE LIS
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];//if prev = -1 so add 1 with prev everywhere
        int inc = 0;
        if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
            inc = cuboids[curr][2] + solveMem(cuboids, curr+1, curr, dp);
        }
        int exc = 0 + solveMem(cuboids, curr+1, prev, dp);
        dp[curr][prev+1] = max(inc, exc);
        return dp[curr][prev+1];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int curr = 0;
        int prev = -1;
        int n = cuboids.size();
        //Sort each cuboid to get max height at index 2 
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        //SORT CUBOIDS FOR BASE LENGTH OR BREADTH
        sort(cuboids.begin(), cuboids.end());
        // return solveRec(cuboids, curr, prev);
        vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        return solveMem(cuboids,curr, prev, dp);
    }
};