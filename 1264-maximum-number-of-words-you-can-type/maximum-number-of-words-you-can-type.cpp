class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool mp[26];
        for(char &ch : brokenLetters){
            mp[ch-'a'] = true;
        }
        int result = 0;
        bool canType = true;
        for(char &ch : text){
            if(ch == ' '){
                if(canType){
                    result++;
                }
                canType = true;
            }else if(mp[ch-'a'] == true){
                canType = false;
            }
        }
        if(canType){
            result++;
        }
        return result;
    }
};