class Solution {
public:
    int maxFreqSum(string s) {
        int maxVowel = 0;
        int maxCons = 0;
        string vowel = "aeiou";
        unordered_map<char, int> freq;
        for(char ch:s){
            freq[ch]++;
            if(vowel.find(ch) != string::npos){
                maxVowel = max(maxVowel, freq[ch]);
            }else{
                maxCons = max(maxCons, freq[ch]);
            }
        }
        return maxVowel + maxCons;
    }
};