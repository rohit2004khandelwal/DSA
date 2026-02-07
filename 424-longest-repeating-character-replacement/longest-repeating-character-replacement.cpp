class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i=0,j=0;
        int winSize = 0;
        int maxFreq = 0;
        int len = 0;
        vector<int> freq(26, 0);
        while(j < n){
            freq[s[j] - 'A']++;
            winSize = j-i+1;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            while(winSize - maxFreq > k){
                freq[s[i] - 'A']--;
                i++;
                winSize = j-i+1;
            }
            if(winSize - maxFreq <= k){
                len = max(len, j-i+1);
            }
            j++;
        }
        return len;
    }
};