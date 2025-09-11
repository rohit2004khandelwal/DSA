class Solution {
public:
    bool isVowel(char c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        for(char &c:s){
            if(isVowel(c)){
                mp[c]++;
            }
        }
        string temp = "AEIOUaeiou";
        int j=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                while(mp[temp[j]] == 0){
                    j++;
                }
                s[i] = temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
        
    }
};