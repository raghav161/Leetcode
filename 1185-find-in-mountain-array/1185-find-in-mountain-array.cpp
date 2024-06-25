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
    int findInMountainArray(int target, MountainArray &arr) {
        int n=arr.length(), l=0, r=n-1;
        while(l<=r) 
        {
            int mid=l+(r-l)/2;
            if(arr.get(mid) < arr.get(mid+1))
                l=mid+1;
            else
                r=mid-1;
        }
        int maxi=l;
        l=0, r=maxi;
        while(l<=r) 
        {
            int mid=l+(r-l)/2, middle=arr.get(mid);
            if(middle==target)
                return mid;
            else if(middle < target)
                l=mid+1;
            else
                r=mid-1;
        }
        l=maxi+1, r=n-1;
        while(l<=r) 
        {
            int mid=l+(r-l)/2, middle=arr.get(mid);
            if(middle==target)
                return mid;
            else if(middle < target)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
};