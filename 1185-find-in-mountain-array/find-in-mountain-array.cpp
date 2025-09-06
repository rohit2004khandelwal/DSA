/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndex(MountainArray &mountainArr){
        int s=0;
        int n = mountainArr.length() - 1;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) s=mid+1;
            else{
                e = mid;
            }
            mid = s + (e-s)/2; 
        }
        return s;
    }
    //BINARY SEARCH
    int binarySearch(int target, MountainArray &mountainArr, int s, int e, bool asc){
        
        while(s<=e){
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;

            if(asc){
                if(val < target) s=mid+1;
                else e=mid-1;
            }else{
                if(val < target) e=mid-1;
                else s=mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakValue = peakIndex(mountainArr);
        //LEFT CHECKING
        int leftVal = binarySearch(target, mountainArr, 0, peakValue, true);
        if(leftVal != -1) return leftVal;
        //RIGHT CHECKING
        return binarySearch(target, mountainArr, peakValue+1, mountainArr.length()-1, false);
    }
};