class Solution {
public:
    bool doesAliceWin(string s) {
        string vowel = "aeiou";
        for(char ch : s){
            if(vowel.find(ch) != string::npos){
                return true;
            }
        }
        return false;
    }
};