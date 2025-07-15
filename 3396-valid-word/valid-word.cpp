class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool isVowel = false;
        bool isCons = false;
        for(char ch : word){
            if(isalpha(ch)){
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    isVowel = true;
                }else{
                    isCons = true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }
        return isVowel && isCons;
    }
};