class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int size = pow(2,k);//CALCULATIN TOTAL POSSIBLE BINARY CODE OF LENGTH K
        set<string> st;
        for(int i=0; i<=n-k; i++){
            st.insert(s.substr(i,k));
        }
        return st.size() == size;
    }
};