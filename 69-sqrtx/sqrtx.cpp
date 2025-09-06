class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long long int mid = s+(e-s)/2;
        int ans = -1;
        while(s<=e){
            long long int product = mid*mid;
            if(product == x) return mid;
            else if(product < x){
                ans = mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
        
    }
};