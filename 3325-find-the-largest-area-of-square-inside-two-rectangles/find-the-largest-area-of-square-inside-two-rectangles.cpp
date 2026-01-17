class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long area = 0;
        int n = bottomLeft.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                long long leftA = bottomLeft[i][0];
                long long bottomA = bottomLeft[i][1];
                long long rightA = topRight[i][0];
                long long topA = topRight[i][1];

                long long leftB = bottomLeft[j][0];
                long long bottomB = bottomLeft[j][1];
                long long rightB = topRight[j][0];
                long long topB = topRight[j][1];

                long long L = max(leftA, leftB);
                long long B = max(bottomA, bottomB);
                long long R = min(rightA, rightB);
                long long T = min(topA, topB);

                if(L < R && B < T){
                    long long side = min(R - L, T - B);
                    area = max(area, side * side);
                }
            }
        }
        return area;
    }
};