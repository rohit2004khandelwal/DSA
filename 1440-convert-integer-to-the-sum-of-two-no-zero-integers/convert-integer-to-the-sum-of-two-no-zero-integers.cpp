class Solution {
public:
    bool check(int num){
        while(num){
            if(num%10 == 0){
                return false;
            }
            num/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a=1;a<n;a++){
            int b=n-a;
            if(check(a) && check(b)){
                return {a, b};
            }
        }
        return {};
    }
};