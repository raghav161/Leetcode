class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size()+1), ans;
        pre[0]=0;
        for(int i=1;i<=arr.size();i++)
            pre[i]=pre[i-1]^arr[i-1];
        for(auto i:queries)
            ans.push_back(pre[i[1]+1]^pre[i[0]]);
        return ans;
    }
};