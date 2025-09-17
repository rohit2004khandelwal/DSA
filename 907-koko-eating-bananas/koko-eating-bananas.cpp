class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h){
        int actualHour = 0;
        for(int &x:piles){
            actualHour += x/mid;
            if(x%mid != 0) actualHour++;
        }
        return actualHour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int s=1;
        int e=*max_element(begin(piles), end(piles));
        while(s<e){
            int mid=s+(e-s)/2;
            if(canEat(piles, mid, h)){
                e=mid;
            }else{
                s=mid+1;
            }
        }
        return s;
    }
};