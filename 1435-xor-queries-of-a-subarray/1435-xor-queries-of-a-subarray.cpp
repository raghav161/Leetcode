class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size()+1), ans;
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++)
            pre[i]=pre[i-1]^arr[i];
        for(auto i:queries)
        {
            int left=0;
            if(i[0]>=1)
                left=pre[i[0]-1];
            ans.push_back(pre[i[1]]^left);
        }
        return ans;
    }
};