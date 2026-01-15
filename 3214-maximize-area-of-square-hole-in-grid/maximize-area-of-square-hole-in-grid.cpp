class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int side = 1;
        int area = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxH = 1;
        int currH = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] == hBars[i-1] + 1){
                currH++;
            }else{
                currH = 1;
            }
            maxH = max(maxH, currH);
        }

        int currV = 1;
        int maxV = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] == vBars[i-1] + 1){
                currV++;
            }else{
                currV = 1;
            }
            maxV = max(maxV, currV);
        }
        side = min(maxH + 1, maxV + 1);
        return area = side*side;
    }
};