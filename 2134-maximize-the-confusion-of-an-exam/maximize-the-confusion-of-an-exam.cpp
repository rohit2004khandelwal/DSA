class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int i=0,j=0;
        int ans = 0;
        int winSize = 0;
        int maxFreq = 0;
        unordered_map<int , int>mp;
        while(j < n){
            mp[answerKey[j]]++;
            winSize = j-i+1;
            maxFreq = max(maxFreq, mp[answerKey[j]]);
            while(winSize - maxFreq > k){
                mp[answerKey[i]]--;
                i++;
                winSize = j-i+1;
            }
            if(winSize - maxFreq <= k){
                ans = max(ans, j-i+1);
            }
            j++;
        }
        return ans;
    }
};