class Solution {
public:
    long long removeZeros(long long n) {
        string x;
        string s = to_string(n);
        for(int i=0; i<s.size(); i++){
            if(s[i] != '0'){
                x += s[i];
            }
        }
        return stoll(x);
    }
};