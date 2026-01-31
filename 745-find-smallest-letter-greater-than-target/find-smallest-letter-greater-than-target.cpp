class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int pos = -1;
        int ans = INT_MAX;;
        for(int i=0; i<n; i++){
            if(letters[i] > target){
                pos = i;
                ans = min(ans , pos);
            }
        }
        if(pos == -1) return letters[0];
        return letters[ans];
    }
};