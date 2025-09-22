class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>psum(n+1, 0);
        int maxPrefix = 0;//HAME BOLA HAI INITIAL 0 HAI TOH INT_MIN MAT LENA NEGATIVE CHALE JAYEGA
        for(int i=1;i<=n;i++){
            psum[i] = psum[i-1] + gain[i-1];//LOOP MAI <= ISLIYE LIYA TAKI GAIN KE SARE INCLUDE HO
            maxPrefix = max(maxPrefix, psum[i]);
        }
        return maxPrefix;
    }
};