class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++){
                vector<int> freq(26, 0);
                int distinct = 0;
                int maxFreq = 0;
            for(int j=i; j<n; j++){
                if(freq[s[j] - 'a'] == 0) distinct++;
                freq[s[j] - 'a']++;

                maxFreq = max(maxFreq, freq[s[j] - 'a']);
                int len = j-i+1;
                if(len == distinct * maxFreq){
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};