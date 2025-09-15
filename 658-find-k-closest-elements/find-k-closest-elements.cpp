class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //CUSTOM COMPARATOR
        // sort(arr.begin(), arr.end(), [x](int a, int b){
        //     if(abs(a-x) == abs(b-x)){
        //         return a < b;
        //     }
        //     return abs(a-x) < abs(b-x);
        // });
        // vector<int> ans(arr.begin(), arr.begin()+k);
        // sort(ans.begin(), ans.end());
        // return ans;
        int l=0,h=arr.size()-1;
        while(h-l>=k){
            if(x-arr[l] > arr[h]-x) l++;
            else h--;
        }
        vector<int> ans;
        for(int i=l;i<=h;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};