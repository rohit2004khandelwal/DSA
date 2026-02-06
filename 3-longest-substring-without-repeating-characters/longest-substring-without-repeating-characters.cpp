class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0,j=0;
        int len = INT_MIN;
        unordered_map<char, int>mp;
        if(s.empty()) return 0;
        while(j < n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            if(mp[s[j]] == 1){
                len = max(len, j-i+1);
            }
            j++;
        }
        return len;
    }
};