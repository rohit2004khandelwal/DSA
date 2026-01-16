class Solution {
public:
    int M = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> s1;
        unordered_set<int> s2;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i=0; i<hFences.size()-1; i++){
            for(int j=i+1; j<hFences.size(); j++){
                s1.insert(hFences[j]-hFences[i]);
            }
        }
        int maxSide = -1;
        for(int i=0; i<vFences.size()-1; i++){
            for(int j=i+1; j<vFences.size(); j++){
                int gap = vFences[j]-vFences[i];
                if(s1.count(gap)){
                    maxSide = max(maxSide, gap);
                }
            }
        }
        if(maxSide == -1) return -1;
        long long area = 1LL*maxSide*maxSide;
        return (area % M);
    }
};