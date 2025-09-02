class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        //UPPER POINT A
        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            //LOWER RIGHT B
            for(int j=0;j<n;j++){
                if(i == j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 <= x2 && y1>= y2){
                    bool hasPoint = false;
                    for(int k=0;k<n;k++){    //CHECKING POINT FOR RECTANGLE
                        if(k == i || k == j) continue;
                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if(x3 >= x1 && x3 <= x2 && y3 >= y2 && y3 <= y1){
                            hasPoint = true;
                            break;
                        }
                    }
                    if(!hasPoint){
                        result++;
                    }
                }
            }
        }
        return result;
    }
};