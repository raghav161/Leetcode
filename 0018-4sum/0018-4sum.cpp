class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<vector<int>> ans;
        if(n<4)
            return ans;
        set<vector<int>> s;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int low=j+1, high=n-1;
                while(low<high)
                {
                    long long sum=(long long)arr[i]+arr[j]+arr[low]+arr[high];
                    if(sum==k)
                    {
                        s.insert({arr[i],arr[j],arr[low],arr[high]});
                        low++;
                        high--;
                    }
                    else if(sum>k)
                        high--;
                    else if(sum<k)
                        low++;
                }
            }
        }
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};