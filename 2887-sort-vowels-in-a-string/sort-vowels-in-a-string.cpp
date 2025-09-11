class Solution {
public:
    bool isVowel(char c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        string temp;
        for(char c : s){
            if(isVowel(c)){
                temp += c;
            }
        }
        sort(temp.begin(), temp.end());
        string ans;
        int j=0;
        for(int i=0;i<=s.length()-1;i++){
            if(isVowel(s[i])){
                ans += temp[j];
                j++;
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};