class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(n > m) return "";
        int i=0,j=0;
        int winSize = INT_MAX;
        int reqCount = n;
        int start_i = 0;
        unordered_map<char, int>mp;
        for(char &ch:t){
            mp[ch]++;
        }
        while(j < m){   //BCOZ HUM STRING S PAR TRAVERSE KAR RHE HAI
            char ch = s[j];
            if(mp[ch] > 0) reqCount--;
            mp[ch]--;
            while(reqCount == 0){
                //SHRINK
                if (j - i + 1 < winSize) {
                    winSize = j - i + 1;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) reqCount++;
                i++;
            }
            j++;
        }
        return winSize == INT_MAX ? "" : s.substr(start_i, winSize);
    }
};