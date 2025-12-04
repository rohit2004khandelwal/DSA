class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        //BOUNDARY CASES
        int i = 0;
        while(i < n && directions[i] == 'L') i++;
        int j = n-1;
        while(j >= 0 && directions[j] == 'R') j--;

        //MAIN 
        int collisions = 0;
        while(i <= j){
            if(directions[i] != 'S'){
                collisions++;
            }
            i++;
        }
        return collisions;
    }
};