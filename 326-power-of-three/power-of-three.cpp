class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n<=0) return false;
        // while(n%3 == 0){
        //     n/=3;
        // }
        // return n==1;
        //APPROACH 3
        // if(n<=0) return false;
        // double x = log10(n) / log10(3);
        // return x == (int)x;
        //APPROACH 4
        return n>0 && 1162261467%n == 0;
    }
};