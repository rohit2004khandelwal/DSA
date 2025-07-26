class Solution {
public: 
    bool solveRec(string &s, string &p, int i, int j){
        //BASE CASE
        if(i == s.length() && j == p.length()) return true;
        if(j == p.length()) return false;
        //MAIN CASE
        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i]==p[j]);
        if(j+1 < p.length() && p[j+1] == '*'){
            bool emptyCase = solveRec(s,p,i,j+2);//jab empty le rhe ho
            bool elementCase = currMatch && solveRec(s,p,i+1,j);//jab preceding element imagine kar rhe ho fir currMatch bhi check karo 
            return emptyCase || elementCase;
        }
        else if(currMatch){
            return solveRec(s,p,i+1,j+1);
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return solveRec(s,p,0,0);
    }
};