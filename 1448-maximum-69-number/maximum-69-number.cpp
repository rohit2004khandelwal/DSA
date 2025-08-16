class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(char &ch:s){
            if(ch == '6'){
                ch = '9';// change first 6 → 9
                break; // stop after one change
            }
        }
        return stoi(s);
    }
};