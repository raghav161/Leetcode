class Solution {
public:
    bool f(vector<int>& arr, int maxOp, int mid){
        int count=0;
        for(auto a:arr)
            count+=(a-1)/mid;
        return count<=maxOp;
    }
    int minimumSize(vector<int>& arr, int maxOp) {
        int low=1, high=*max_element(arr.begin(), arr.end());
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            if(f(arr, maxOp, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high+1;
    }
};