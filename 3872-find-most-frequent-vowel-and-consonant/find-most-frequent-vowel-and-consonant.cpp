class Solution {
public:
    int maxFreqSum(string s) {
        int maxVowel = 0;
        int maxCons  = 0;

        int arr[26] = {0};

        for(char &ch : s) {
            arr[ch-'a']++;

            if(string("aeiou").find(ch) != string::npos) {
                maxVowel = max(maxVowel, arr[ch-'a']);
            } else {
                maxCons = max(maxCons, arr[ch-'a']);
            }
        }

        return maxCons + maxVowel;
    }
};